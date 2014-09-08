/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2007 Andreas Obergrusberger <tradiaz@yahoo.de>
 * Copyright (C) 2008-2010 Valeriy Lyasotskiy <onestep@ukr.net>
 * Copyright (C) 2010-2011 Jonathan Conder <jonno.conder@gmail.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <alpm.h>
#include <pk-backend.h>

#include "pk-backend-alpm.h"
#include "pk-backend-databases.h"
#include "pk-backend-error.h"
#include "pk-backend-install.h"
#include "pk-backend-transaction.h"

static gint
alpm_add_file (const gchar *filename)
{
	alpm_pkg_t *pkg;
	alpm_siglevel_t level;

	g_return_val_if_fail (filename != NULL, -1);
	g_return_val_if_fail (alpm != NULL, -1);

	level = alpm_option_get_local_file_siglevel (alpm);

	if (alpm_pkg_load (alpm, filename, 1, level, &pkg) < 0) {
		return -1;
	}

	if (alpm_add_pkg (alpm, pkg) < 0) {
		alpm_pkg_free (pkg);
		return -1;
	}

	return 0;
}

static gboolean
pk_backend_transaction_add_targets (PkBackendJob *job, gchar** paths, GError **error)
{
	g_return_val_if_fail (job != NULL, FALSE);

	g_return_val_if_fail (paths != NULL, FALSE);

	for (; *paths != NULL; ++paths) {
		if (alpm_add_file (*paths) < 0) {
			alpm_errno_t errno = alpm_errno (alpm);
			g_set_error (error, ALPM_ERROR, errno, "%s: %s",
				     *paths, alpm_strerror (errno));
			return FALSE;
		}
	}

	return TRUE;
}

static void
pk_backend_install_files_thread (PkBackendJob *job, GVariant* params, gpointer p)
{
	gboolean only_trusted;
	GError *error = NULL;
	gchar** full_paths;
	PkBitfield flags;

	pkalpm_end_job_if_fail (job != NULL, job);

	g_variant_get(params, "(t^a&s)",
				  &flags,
				  &full_paths);
	only_trusted = flags & PK_TRANSACTION_FLAG_ENUM_ONLY_TRUSTED;

	if (!only_trusted && !pkalpm_backend_disable_signatures (&error)) {
		goto out;
	}

	if (pk_backend_transaction_initialize (job, 0, 0, &error) &&
	    pk_backend_transaction_add_targets (job, full_paths, &error) &&
	    pk_backend_transaction_simulate (&error)) {
		pk_backend_transaction_commit (job, &error);
	}

out:
	pk_backend_transaction_end (job, (error == NULL) ? &error : NULL);

	if (!only_trusted) {
		GError **e = (error == NULL) ? &error : NULL;
		pkalpm_backend_enable_signatures (e);
	}

	pk_backend_finish (job, error);
}

void
pk_backend_install_files (PkBackend *self,
                          PkBackendJob   *job,
                          PkBitfield  transaction_flags,
                          gchar      **full_paths)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (full_paths != NULL);

	pkalpm_backend_run (job, PK_STATUS_ENUM_SETUP,
			pk_backend_install_files_thread, NULL);
}
