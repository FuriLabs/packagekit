/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2013 Richard Hughes <richard@hughsie.com>
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

#ifndef __HIF_GOAL_H
#define __HIF_GOAL_H

#include <glib.h>
#include <pk-backend.h>

#include <hawkey/goal.h>
#include <hawkey/package.h>

gboolean	 hif_goal_is_upgrade_package		(HyGoal		 goal,
							 HyPackage	 package);
gboolean	 hif_goal_depsolve			(HyGoal		 goal,
							 GError		**error);
GPtrArray	*hif_goal_get_packages			(HyGoal		 goal,
							 PkBitfield	 types);

#endif /* __HIF_GOAL_H */
