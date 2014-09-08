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

#include "pk-backend-alpm.h"
#include "pk-backend-error.h"
#include "pk-backend-groups.h"
#include "pk-backend-packages.h"

gchar *
alpm_pkg_build_id (alpm_pkg_t *pkg)
{
	const gchar *name, *version, *arch, *repo;

	g_return_val_if_fail (pkg != NULL, NULL);

	name = alpm_pkg_get_name (pkg);
	version = alpm_pkg_get_version (pkg);

	arch = alpm_pkg_get_arch (pkg);
	if (arch == NULL) {
		arch = "any";
	}

	/* TODO: check correctness */
	if (alpm_pkg_get_origin (pkg) == ALPM_PKG_FROM_SYNCDB) {
		repo = alpm_db_get_name (alpm_pkg_get_db (pkg));
	} else {
		repo = "installed";
	}

	return pk_package_id_build (name, version, arch, repo);
}

void
pkalpm_backend_pkg (PkBackendJob *job, alpm_pkg_t *pkg, PkInfoEnum info)
{
	gchar *package;

	g_return_if_fail (job != NULL);
	g_return_if_fail (pkg != NULL);

	package = alpm_pkg_build_id (pkg);
	pk_backend_job_package (job, info, package, alpm_pkg_get_desc (pkg));
	g_free (package);
}

alpm_pkg_t *
pkalpm_backend_find_pkg (PkBackendJob *job, const gchar *package_id, GError **error)
{
	gchar **package;
	const gchar *repo_id;
	alpm_db_t *db = NULL;
	alpm_pkg_t *pkg;

	g_return_val_if_fail (job != NULL, NULL);
	g_return_val_if_fail (package_id != NULL, NULL);
	g_return_val_if_fail (alpm != NULL, NULL);
	g_return_val_if_fail (localdb != NULL, NULL);

	package = pk_package_id_split (package_id);
	repo_id = package[PK_PACKAGE_ID_DATA];

	/* find the database to search in */
	if (g_strcmp0 (repo_id, "installed") == 0) {
		db = localdb;
	} else {
		const alpm_list_t *i = alpm_get_syncdbs (alpm);
		for (; i != NULL; i = i->next) {
			const gchar *repo = alpm_db_get_name (i->data);

			if (g_strcmp0 (repo, repo_id) == 0) {
				db = i->data;
				break;
			}
		}
	}

	if (db != NULL) {
		pkg = alpm_db_get_pkg (db, package[PK_PACKAGE_ID_NAME]);
	} else {
		pkg = NULL;
	}

	if (pkg != NULL) {
		const gchar *version = alpm_pkg_get_version (pkg);
		if (g_strcmp0 (version, package[PK_PACKAGE_ID_VERSION]) != 0) {
			pkg = NULL;
		}
	}

	if (pkg == NULL) {
		int code = ALPM_ERR_PKG_NOT_FOUND;
		g_set_error (error, ALPM_ERROR, code, "%s: %s", package_id,
			     alpm_strerror (code));
	}
	g_strfreev (package);
	return pkg;
}

static gboolean
pk_backend_resolve_package (PkBackendJob *job, const gchar *package, PkBitfield filters, GError **error)
{
	alpm_pkg_t *pkg;
	
	gboolean skip_local, skip_remote;

	g_return_val_if_fail (job != NULL, FALSE);
	g_return_val_if_fail (package != NULL, FALSE);
	g_return_val_if_fail (localdb != NULL, FALSE);

	pkg = pkalpm_backend_find_pkg (job, package, error);
	if (pkg == NULL) {
		return FALSE;
	}

	skip_local = pk_bitfield_contain (filters, PK_FILTER_ENUM_NOT_INSTALLED);
	skip_remote = pk_bitfield_contain (filters, PK_FILTER_ENUM_INSTALLED);

	if (alpm_pkg_get_origin (pkg) == ALPM_PKG_FROM_LOCALDB) {
		if (!skip_local) {
			pkalpm_backend_pkg (job, pkg, PK_INFO_ENUM_INSTALLED);
		}
	} else {
		if (!skip_remote) {
			pkalpm_backend_pkg (job, pkg, PK_INFO_ENUM_AVAILABLE);
		}
	}

	return TRUE;
}

static gboolean
pk_backend_resolve_name (PkBackendJob *job, const gchar *name, PkBitfield filters, GError **error)
{
	alpm_pkg_t *pkg;
	int code;
	
	gboolean skip_local, skip_remote;

	g_return_val_if_fail (job != NULL, FALSE);
	g_return_val_if_fail (name != NULL, FALSE);
	g_return_val_if_fail (alpm != NULL, FALSE);
	g_return_val_if_fail (localdb != NULL, FALSE);

	skip_local = pk_bitfield_contain (filters, PK_FILTER_ENUM_NOT_INSTALLED);
	skip_remote = pk_bitfield_contain (filters, PK_FILTER_ENUM_INSTALLED);

	pkg = alpm_db_get_pkg (localdb, name);
	if (pkg != NULL) {
		if (!skip_local) {
			pkalpm_backend_pkg (job, pkg, PK_INFO_ENUM_INSTALLED);
			return TRUE;
		}
	} else if (!skip_remote) {
		const alpm_list_t *i = alpm_get_syncdbs (alpm);
		for (; i != NULL; i = i->next) {
			pkg = alpm_db_get_pkg (i->data, name);
			if (pkg != NULL) {
				pkalpm_backend_pkg (job, pkg,
						PK_INFO_ENUM_AVAILABLE);
				return TRUE;
			}
		}
	}

	code = ALPM_ERR_PKG_NOT_FOUND;
	g_set_error (error, ALPM_ERROR, code, "%s: %s", name,
		     alpm_strerror (code));
	return FALSE;
}

static void
pk_backend_resolve_thread (PkBackendJob *job, GVariant* params, gpointer p)
{
	const gchar **search;
	GError *error = NULL;
	PkBitfield filters;

	pkalpm_end_job_if_fail (job != NULL, job);

	g_variant_get(params, "(t^a&s)",
				  &filters,
				  &search);

	pkalpm_end_job_if_fail (search != NULL, job);

	for (; *search != NULL; ++search) {
		if (pk_backend_cancelled (job)) {
			break;
		}

		/* find a package with the given id or name */
		if (pk_package_id_check (*search)) {
			if (!pk_backend_resolve_package (job, *search, filters, &error)) {
				break;
			}
		} else {
			if (!pk_backend_resolve_name (job, *search, filters, &error)) {
				break;
			}
		}
	}

	pk_backend_finish (job, error);
}

void
pk_backend_resolve (PkBackend   *self,
                    PkBackendJob   *job,
                    PkBitfield  filters,
					gchar      **search)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (search != NULL);

	pkalpm_backend_run (job, PK_STATUS_ENUM_QUERY, pk_backend_resolve_thread, NULL);
}

static void
pk_backend_get_details_thread (PkBackendJob *job, GVariant* params, gpointer p)
{
	gchar **packages;
	GError *error = NULL;

	pkalpm_end_job_if_fail (job != NULL, job);
	pkalpm_end_job_if_fail (localdb != NULL, job);

	packages = (gchar**) p;

	pkalpm_end_job_if_fail (packages != NULL, job);

	for (; *packages != NULL; ++packages) {
		alpm_pkg_t *pkg;
		const alpm_list_t *i;

		GString *licenses;
		PkGroupEnum group;
		const gchar *desc, *url;
		gulong size;

		if (pk_backend_cancelled (job)) {
			break;
		}

		pkg = pkalpm_backend_find_pkg (job, *packages, &error);
		if (pkg == NULL) {
			break;
		}

		i = alpm_pkg_get_licenses (pkg);
		if (i == NULL) {
			licenses = g_string_new ("Unknown");
		} else {
			licenses = g_string_new ((const gchar *) i->data);
			while ((i = i->next) != NULL) {
				const gchar *license = (const gchar *) i->data;
				/* assume OR although it may not be correct */
				g_string_append_printf (licenses, " or %s",
							license);
			}
		}

		group = pk_group_enum_from_string (alpm_pkg_get_group (pkg));
		desc = alpm_pkg_get_desc (pkg);
		url = alpm_pkg_get_url (pkg);

		if (alpm_pkg_get_origin (pkg) == ALPM_PKG_FROM_LOCALDB) {
			size = alpm_pkg_get_isize (pkg);
		} else {
			size = alpm_pkg_download_size (pkg);
		}

		pk_backend_job_details (job, *packages, NULL, licenses->str, group,
					desc, url, size);
		g_string_free (licenses, TRUE);
	}

	pk_backend_finish (job, error);
}

void
pk_backend_get_details (PkBackend   *self,
                        PkBackendJob   *job,
                        gchar      **package_ids)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (package_ids != NULL);

	pkalpm_backend_run (job, PK_STATUS_ENUM_QUERY,
			pk_backend_get_details_thread, package_ids);
}

static void
pk_backend_get_files_thread (PkBackendJob *job, GVariant* params, gpointer p)
{
	gchar **packages;
	GError *error = NULL;

	pkalpm_end_job_if_fail (job != NULL, job);
	pkalpm_end_job_if_fail (alpm != NULL, job);

	packages = (gchar**) p;

	pkalpm_end_job_if_fail (packages != NULL, job);

	for (; *packages != NULL; ++packages) {
		alpm_pkg_t *pkg;
		const gchar *root;

		GString *files;
		alpm_filelist_t *filelist;
		gsize i;

		if (pk_backend_cancelled (job)) {
			break;
		}

		pkg = pkalpm_backend_find_pkg (job, *packages, &error);
		if (pkg == NULL) {
			break;
		}

		root = alpm_option_get_root (alpm);
		files = g_string_new ("");

		filelist = alpm_pkg_get_files (pkg);
		for (i = 0; i < filelist->count; ++i) {
			const gchar *file = filelist->files[i].name;
			g_string_append_printf (files, "%s%s;", root, file);
		}

		g_string_truncate (files, MAX (files->len, 1) - 1);
		pk_backend_job_files (job, *packages, &files->str);
		g_string_free (files, TRUE);
	}

	pk_backend_finish (job, error);
}

void
pk_backend_get_files (PkBackend *self,
                      PkBackendJob   *job,
                      gchar      **package_ids)
{
	g_return_if_fail (self != NULL);
	g_return_if_fail (package_ids != NULL);

	pkalpm_backend_run (job, PK_STATUS_ENUM_QUERY,
			pk_backend_get_files_thread, package_ids);
}
