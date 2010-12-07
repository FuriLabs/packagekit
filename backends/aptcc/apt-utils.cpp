/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2009 Daniel Nicoletti <dantti85-pk@yahoo.com.br>
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

#include "apt-utils.h"

#include "pkg_acqfile.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>

static int descrBufferSize = 4096;
static char *descrBuffer = new char[descrBufferSize];

static char *debParser(string descr);

string get_default_short_description(const pkgCache::VerIterator &ver,
				    pkgRecords *records)
{
	if(ver.end() || ver.FileList().end() || records == NULL) {
		return string();
	}

	pkgCache::VerFileIterator vf = ver.FileList();

	if (vf.end()) {
		return string();
	} else {
		return records->Lookup(vf).ShortDesc();
	}
}

string get_short_description(const pkgCache::VerIterator &ver,
			    pkgRecords *records)
{
	if (ver.end() || ver.FileList().end() || records == NULL) {
		return string();
	}

	pkgCache::DescIterator d = ver.TranslatedDescription();

	if (d.end()) {
		return string();
	}

	pkgCache::DescFileIterator df = d.FileList();

	if (df.end()) {
		return string();
	} else {
		return records->Lookup(df).ShortDesc();
	}
}

string get_long_description(const pkgCache::VerIterator &ver,
				pkgRecords *records)
{
	if (ver.end() || ver.FileList().end() || records == NULL) {
		return string();
	}

	pkgCache::DescIterator d = ver.TranslatedDescription();

	if (d.end()) {
		return string();
	}

	pkgCache::DescFileIterator df = d.FileList();

	if (df.end()) {
		return string();
	} else {
		return records->Lookup(df).LongDesc();
	}
}

string get_long_description_parsed(const pkgCache::VerIterator &ver,
				pkgRecords *records)
{
	return debParser(get_long_description(ver, records));
}

string get_default_long_description(const pkgCache::VerIterator &ver,
				    pkgRecords *records)
{
	if(ver.end() || ver.FileList().end() || records == NULL) {
		return string();
	}

	pkgCache::VerFileIterator vf = ver.FileList();

	if (vf.end()) {
		return string();
	} else {
		return records->Lookup(vf).LongDesc();
	}
}

static char *debParser(string descr)
{
	// Policy page on package descriptions
	// http://www.debian.org/doc/debian-policy/ch-controlfields.html#s-f-Description
	unsigned int i;
	string::size_type nlpos=0;

	nlpos = descr.find('\n');
	// delete first line
	if (nlpos != string::npos) {
		descr.erase(0, nlpos + 2);        // del "\n " too
	}

	// avoid replacing '\n' for a ' ' after a '.\n' is found
	bool removedFullStop = false;
	while (nlpos < descr.length()) {
		// find the new line position
		nlpos = descr.find('\n', nlpos);
		if (nlpos == string::npos) {
			// if it could not find the new line
			// get out of the loop
			break;
		}

		i = nlpos;
		// erase the char after '\n' which is always " "
		descr.erase(++i, 1);

		// remove lines likes this: " .", making it a \n
		if (descr[i] == '.') {
			descr.erase(i, 1);
			nlpos = i;
			// don't permit the next round to replace a '\n' to a ' '
			removedFullStop = true;
			continue;
		} else if (descr[i] != ' ' && removedFullStop == false) {
			// it's not a line to be verbatim displayed
			// So it's a paragraph let's replace '\n' with a ' '
			// replace new line with " "
			descr.replace(nlpos, 1, " ");
		}

		removedFullStop = false;
		nlpos++;
	}
	strcpy(descrBuffer, descr.c_str());
	return descrBuffer;
}

PkGroupEnum
get_enum_group (string group)
{
	if (group.compare ("admin") == 0) {
		return PK_GROUP_ENUM_ADMIN_TOOLS;
	} else if (group.compare ("base") == 0) {
		return PK_GROUP_ENUM_SYSTEM;
	} else if (group.compare ("comm") == 0) {
		return PK_GROUP_ENUM_COMMUNICATION;
	} else if (group.compare ("devel") == 0) {
		return PK_GROUP_ENUM_PROGRAMMING;
	} else if (group.compare ("doc") == 0) {
		return PK_GROUP_ENUM_DOCUMENTATION;
	} else if (group.compare ("editors") == 0) {
		return PK_GROUP_ENUM_PUBLISHING;
	} else if (group.compare ("electronics") == 0) {
		return PK_GROUP_ENUM_ELECTRONICS;
	} else if (group.compare ("embedded") == 0) {
		return PK_GROUP_ENUM_SYSTEM;
	} else if (group.compare ("fonts") == 0) {
		return PK_GROUP_ENUM_FONTS;
	} else if (group.compare ("games") == 0) {
		return PK_GROUP_ENUM_GAMES;
	} else if (group.compare ("gnome") == 0) {
		return PK_GROUP_ENUM_DESKTOP_GNOME;
	} else if (group.compare ("graphics") == 0) {
		return PK_GROUP_ENUM_GRAPHICS;
	} else if (group.compare ("hamradio") == 0) {
		return PK_GROUP_ENUM_COMMUNICATION;
	} else if (group.compare ("interpreters") == 0) {
		return PK_GROUP_ENUM_PROGRAMMING;
	} else if (group.compare ("kde") == 0) {
		return PK_GROUP_ENUM_DESKTOP_KDE;
	} else if (group.compare ("libdevel") == 0) {
		return PK_GROUP_ENUM_PROGRAMMING;
	} else if (group.compare ("libs") == 0) {
		return PK_GROUP_ENUM_SYSTEM;
	} else if (group.compare ("mail") == 0) {
		return PK_GROUP_ENUM_INTERNET;
	} else if (group.compare ("math") == 0) {
		return PK_GROUP_ENUM_SCIENCE;
	} else if (group.compare ("misc") == 0) {
		return PK_GROUP_ENUM_OTHER;
	} else if (group.compare ("net") == 0) {
		return PK_GROUP_ENUM_NETWORK;
	} else if (group.compare ("news") == 0) {
		return PK_GROUP_ENUM_INTERNET;
	} else if (group.compare ("oldlibs") == 0) {
		return PK_GROUP_ENUM_LEGACY;
	} else if (group.compare ("otherosfs") == 0) {
		return PK_GROUP_ENUM_SYSTEM;
	} else if (group.compare ("perl") == 0) {
		return PK_GROUP_ENUM_PROGRAMMING;
	} else if (group.compare ("python") == 0) {
		return PK_GROUP_ENUM_PROGRAMMING;
	} else if (group.compare ("science") == 0) {
		return PK_GROUP_ENUM_SCIENCE;
	} else if (group.compare ("shells") == 0) {
		return PK_GROUP_ENUM_SYSTEM;
	} else if (group.compare ("sound") == 0) {
		return PK_GROUP_ENUM_MULTIMEDIA;
	} else if (group.compare ("tex") == 0) {
		return PK_GROUP_ENUM_PUBLISHING;
	} else if (group.compare ("text") == 0) {
		return PK_GROUP_ENUM_PUBLISHING;
	} else if (group.compare ("utils") == 0) {
		return PK_GROUP_ENUM_ACCESSORIES;
	} else if (group.compare ("web") == 0) {
		return PK_GROUP_ENUM_INTERNET;
	} else if (group.compare ("x11") == 0) {
		return PK_GROUP_ENUM_DESKTOP_OTHER;
	} else if (group.compare ("alien") == 0) {
		return PK_GROUP_ENUM_UNKNOWN;//FIXME alien is an unknown group?
	} else if (group.compare ("translations") == 0) {
		return PK_GROUP_ENUM_LOCALIZATION;
	} else if (group.compare ("metapackages") == 0) {
		return PK_GROUP_ENUM_COLLECTIONS;
	} else {
		return PK_GROUP_ENUM_UNKNOWN;
	}
}

string getChangelogFile(const string &name,
                        const string &origin,
                        const string &verstr,
                        const string &srcPkg,
                        const string &uri,
                        pkgAcquire *fetcher)
{
   string descr("Changelog for ");
   descr += name;

   // no need to translate this, the changelog is in english anyway
   string filename = "/tmp/aptcc_changelog";

   new pkgAcqFileSane(fetcher, uri, descr, name, filename);

   ofstream out(filename.c_str());
   if(fetcher->Run() == pkgAcquire::Failed) {
      out << "Failed to download the list of changes. " << endl;
      out << "Please check your Internet connection." << endl;
      // FIXME: Need to dequeue the item
   } else {
        struct stat filestatus;
        stat(filename.c_str(), &filestatus );

        if (filestatus.st_size == 0) {
            // FIXME: Use supportedOrigins
            if (origin.compare("Ubuntu") == 0) {
                out << "The list of changes is not available yet.\n" << endl;
                out << "Please use http://launchpad.net/ubuntu/+source/"<< srcPkg <<
                        "/" << verstr << "/+changelog" << endl;
                out << "until the changes become available or try again later." << endl;
            } else {
                out << "This change is not coming from a source that supports changelogs.\n" << endl;
                out << "Failed to fetch the changelog for " << name << endl;
                out << "URI was: " << uri << endl;
            }
        }
   }
   out.close();

   return filename;
}

string getCVEUrls(const string &changelog)
{
    string ret;
    // Regular expression to find cve references
    GRegex *regex;
    GMatchInfo *match_info;
    regex = g_regex_new("CVE-\\d{4}-\\d{4}",
                        G_REGEX_CASELESS,
                        G_REGEX_MATCH_NEWLINE_ANY,
                        0);
    g_regex_match (regex, changelog.c_str(), G_REGEX_MATCH_NEWLINE_ANY, &match_info);
    while (g_match_info_matches(match_info)) {
        gchar *cve = g_match_info_fetch (match_info, 0);
        gchar *cveLink;
        if (!ret.empty()) {
            ret.append(";");
        }
        cveLink = g_strdup_printf("http://web.nvd.nist.gov/view/vuln/detail?vulnId=%s;%s", cve, cve);
        ret.append(cveLink);
        g_free(cveLink);
        g_free(cve);
        g_match_info_next(match_info, NULL);
    }
    g_match_info_free(match_info);
    g_regex_unref(regex);

    return ret;
}

string getBugzillaUrls(const string &changelog)
{
    string ret;
    // Matches Ubuntu bugs
    GRegex *regex;
    GMatchInfo *match_info;
    regex = g_regex_new("LP:\\s+(?:[,\\s*]?#(?'bug'\\d+))*",
                        G_REGEX_CASELESS,
                        G_REGEX_MATCH_NEWLINE_ANY,
                        0);
    g_regex_match (regex, changelog.c_str(), G_REGEX_MATCH_NEWLINE_ANY, &match_info);
    while (g_match_info_matches(match_info)) {
        gchar *bug = g_match_info_fetch_named(match_info, "bug");
        gchar *bugLink;
        if (!ret.empty()) {
            ret.append(";");
        }
        bugLink = g_strdup_printf("https://bugs.launchpad.net/bugs/%s;Launchpad bug #%s", bug, bug);
        ret.append(bugLink);
        g_free(bugLink);
        g_free(bug);
        g_match_info_next(match_info, NULL);
    }
    g_match_info_free(match_info);
    g_regex_unref(regex);

    // Debian bugs
    // Regular expressions to detect bug numbers in changelogs according to the
    // Debian Policy Chapter 4.4. For details see the footnote 15:
    // http://www.debian.org/doc/debian-policy/footnotes.html#f15
    // /closes:\s*(?:bug)?\#?\s?\d+(?:,\s*(?:bug)?\#?\s?\d+)*/i
    regex = g_regex_new("closes:\\s*(?:bug)?\\#?\\s?(?'bug1'\\d+)(?:,\\s*(?:bug)?\\#?\\s?(?'bug2'\\d+))*",
                        G_REGEX_CASELESS,
                        G_REGEX_MATCH_NEWLINE_ANY,
                        0);
    g_regex_match (regex, changelog.c_str(), G_REGEX_MATCH_NEWLINE_ANY, &match_info);
    while (g_match_info_matches(match_info)) {
        gchar *bug1 = g_match_info_fetch_named(match_info, "bug1");
        gchar *bugLink1;
        if (!ret.empty()) {
            ret.append(";");
        }
        bugLink1 = g_strdup_printf("http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=%s;Debian bug #%s", bug1, bug1);
        ret.append(bugLink1);

        gchar *bug2 = g_match_info_fetch_named(match_info, "bug2");
        if (!ret.empty() && bug2 != NULL) {
            gchar *bugLink2;
            ret.append(";");
            bugLink2 = g_strdup_printf("http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=%s;Debian bug #%s", bug1, bug1);
            ret.append(bugLink2);
            g_free(bugLink2);
            g_free(bug2);
        }

        g_free(bugLink1);
        g_free(bug1);
        g_match_info_next(match_info, NULL);
    }
    g_match_info_free(match_info);
    g_regex_unref(regex);

    return ret;
}

bool contains(vector<pair<pkgCache::PkgIterator, pkgCache::VerIterator> > packages,
	    const pkgCache::PkgIterator pkg)
{
	for(vector<pair<pkgCache::PkgIterator, pkgCache::VerIterator> >::iterator it = packages.begin();
	    it != packages.end(); ++it)
	{
		if (it->first == pkg) {
			return true;
		}
	}
	return false;
}

bool ends_with (const string &str, const char *end)
{
	size_t endSize = strlen(end);
	return str.size() >= endSize && (memcmp(str.data() + str.size() - endSize, end, endSize) == 0);
}

bool starts_with (const string &str, const char *start)
{
	size_t startSize = strlen(start);
	return str.size() >= startSize && (strncmp(str.data(), start, startSize) == 0);
}

GDateTime* dateFromString(const gchar *tz,
                          const gchar *year,
                          const gchar *month,
                          const gchar *day,
                          const gchar *hour,
                          const gchar *minute,
                          const gchar *seconds)
{
    GDateTime *ret;
    int monthI;
    if (strcmp(month, "Jan") == 0) {
        monthI = 1;
    } else if (strcmp(month, "Feb") == 0) {
        monthI = 2;
    } else if (strcmp(month, "Mar") == 0) {
        monthI = 3;
    } else if (strcmp(month, "Apr") == 0) {
        monthI = 4;
    } else if (strcmp(month, "May") == 0) {
        monthI = 5;
    } else if (strcmp(month, "Jun") == 0) {
        monthI = 6;
    } else if (strcmp(month, "Jul") == 0) {
        monthI = 7;
    } else if (strcmp(month, "Aug") == 0) {
        monthI = 8;
    } else if (strcmp(month, "Sep") == 0) {
        monthI = 9;
    } else if (strcmp(month, "Oct") == 0) {
        monthI = 10;
    } else if (strcmp(month, "Nov") == 0) {
        monthI = 11;
    } else if (strcmp(month, "Dez") == 0) {
        monthI = 12;
    }

    ret = g_date_time_new(g_time_zone_new(tz),
                          atoi(year),
                          monthI,
                          atoi(day),
                          atoi(hour),
                          atoi(minute),
                          atoi(seconds));
    return ret;
}

const char *utf8(const char *str)
{
   static char *_str = NULL;
   if (str == NULL)
      return NULL;
   if (g_utf8_validate(str, -1, NULL) == true)
      return str;
   g_free(_str);
   _str = NULL;
   _str = g_locale_to_utf8(str, -1, NULL, NULL, NULL);
   return _str;
}
