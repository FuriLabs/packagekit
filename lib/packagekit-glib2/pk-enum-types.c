
/* Generated data (by glib-mkenums) */


#include <glib-object.h>

#ifndef PK_COMPILATION
#define PK_COMPILATION
#endif

#include "pk-client.h"
/* enumerations from "pk-client.h" */
GType pk_client_error_get_type (void) G_GNUC_CONST;

GType
pk_client_error_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_CLIENT_ERROR_FAILED, "PK_CLIENT_ERROR_FAILED", "failed" },
            { PK_CLIENT_ERROR_FAILED_AUTH, "PK_CLIENT_ERROR_FAILED_AUTH", "failed-auth" },
            { PK_CLIENT_ERROR_NO_TID, "PK_CLIENT_ERROR_NO_TID", "no-tid" },
            { PK_CLIENT_ERROR_ALREADY_TID, "PK_CLIENT_ERROR_ALREADY_TID", "already-tid" },
            { PK_CLIENT_ERROR_ROLE_UNKNOWN, "PK_CLIENT_ERROR_ROLE_UNKNOWN", "role-unknown" },
            { PK_CLIENT_ERROR_CANNOT_START_DAEMON, "PK_CLIENT_ERROR_CANNOT_START_DAEMON", "cannot-start-daemon" },
            { PK_CLIENT_ERROR_INVALID_INPUT, "PK_CLIENT_ERROR_INVALID_INPUT", "invalid-input" },
            { PK_CLIENT_ERROR_INVALID_FILE, "PK_CLIENT_ERROR_INVALID_FILE", "invalid-file" },
            { PK_CLIENT_ERROR_NOT_SUPPORTED, "PK_CLIENT_ERROR_NOT_SUPPORTED", "not-supported" },
            { PK_CLIENT_ERROR_DECLINED_SIMULATION, "PK_CLIENT_ERROR_DECLINED_SIMULATION", "declined-simulation" },
            { PK_CLIENT_ERROR_LAST, "PK_CLIENT_ERROR_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkClientError"), values);
    }
    return etype;
}

#include "pk-control.h"
/* enumerations from "pk-control.h" */
GType pk_control_error_get_type (void) G_GNUC_CONST;

GType
pk_control_error_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_CONTROL_ERROR_FAILED, "PK_CONTROL_ERROR_FAILED", "failed" },
            { PK_CONTROL_ERROR_CANNOT_START_DAEMON, "PK_CONTROL_ERROR_CANNOT_START_DAEMON", "cannot-start-daemon" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkControlError"), values);
    }
    return etype;
}

#include "pk-enum.h"
/* enumerations from "pk-enum.h" */
GType pk_role_enum_get_type (void) G_GNUC_CONST;

GType
pk_role_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_ROLE_ENUM_UNKNOWN, "PK_ROLE_ENUM_UNKNOWN", "unknown" },
            { PK_ROLE_ENUM_CANCEL, "PK_ROLE_ENUM_CANCEL", "cancel" },
            { PK_ROLE_ENUM_DEPENDS_ON, "PK_ROLE_ENUM_DEPENDS_ON", "depends-on" },
            { PK_ROLE_ENUM_GET_DETAILS, "PK_ROLE_ENUM_GET_DETAILS", "get-details" },
            { PK_ROLE_ENUM_GET_FILES, "PK_ROLE_ENUM_GET_FILES", "get-files" },
            { PK_ROLE_ENUM_GET_PACKAGES, "PK_ROLE_ENUM_GET_PACKAGES", "get-packages" },
            { PK_ROLE_ENUM_GET_REPO_LIST, "PK_ROLE_ENUM_GET_REPO_LIST", "get-repo-list" },
            { PK_ROLE_ENUM_REQUIRED_BY, "PK_ROLE_ENUM_REQUIRED_BY", "required-by" },
            { PK_ROLE_ENUM_GET_UPDATE_DETAIL, "PK_ROLE_ENUM_GET_UPDATE_DETAIL", "get-update-detail" },
            { PK_ROLE_ENUM_GET_UPDATES, "PK_ROLE_ENUM_GET_UPDATES", "get-updates" },
            { PK_ROLE_ENUM_INSTALL_FILES, "PK_ROLE_ENUM_INSTALL_FILES", "install-files" },
            { PK_ROLE_ENUM_INSTALL_PACKAGES, "PK_ROLE_ENUM_INSTALL_PACKAGES", "install-packages" },
            { PK_ROLE_ENUM_INSTALL_SIGNATURE, "PK_ROLE_ENUM_INSTALL_SIGNATURE", "install-signature" },
            { PK_ROLE_ENUM_REFRESH_CACHE, "PK_ROLE_ENUM_REFRESH_CACHE", "refresh-cache" },
            { PK_ROLE_ENUM_REMOVE_PACKAGES, "PK_ROLE_ENUM_REMOVE_PACKAGES", "remove-packages" },
            { PK_ROLE_ENUM_REPO_ENABLE, "PK_ROLE_ENUM_REPO_ENABLE", "repo-enable" },
            { PK_ROLE_ENUM_REPO_SET_DATA, "PK_ROLE_ENUM_REPO_SET_DATA", "repo-set-data" },
            { PK_ROLE_ENUM_RESOLVE, "PK_ROLE_ENUM_RESOLVE", "resolve" },
            { PK_ROLE_ENUM_SEARCH_DETAILS, "PK_ROLE_ENUM_SEARCH_DETAILS", "search-details" },
            { PK_ROLE_ENUM_SEARCH_FILE, "PK_ROLE_ENUM_SEARCH_FILE", "search-file" },
            { PK_ROLE_ENUM_SEARCH_GROUP, "PK_ROLE_ENUM_SEARCH_GROUP", "search-group" },
            { PK_ROLE_ENUM_SEARCH_NAME, "PK_ROLE_ENUM_SEARCH_NAME", "search-name" },
            { PK_ROLE_ENUM_UPDATE_PACKAGES, "PK_ROLE_ENUM_UPDATE_PACKAGES", "update-packages" },
            { PK_ROLE_ENUM_WHAT_PROVIDES, "PK_ROLE_ENUM_WHAT_PROVIDES", "what-provides" },
            { PK_ROLE_ENUM_ACCEPT_EULA, "PK_ROLE_ENUM_ACCEPT_EULA", "accept-eula" },
            { PK_ROLE_ENUM_DOWNLOAD_PACKAGES, "PK_ROLE_ENUM_DOWNLOAD_PACKAGES", "download-packages" },
            { PK_ROLE_ENUM_GET_DISTRO_UPGRADES, "PK_ROLE_ENUM_GET_DISTRO_UPGRADES", "get-distro-upgrades" },
            { PK_ROLE_ENUM_GET_CATEGORIES, "PK_ROLE_ENUM_GET_CATEGORIES", "get-categories" },
            { PK_ROLE_ENUM_GET_OLD_TRANSACTIONS, "PK_ROLE_ENUM_GET_OLD_TRANSACTIONS", "get-old-transactions" },
            { PK_ROLE_ENUM_REPAIR_SYSTEM, "PK_ROLE_ENUM_REPAIR_SYSTEM", "repair-system" },
            { PK_ROLE_ENUM_GET_DETAILS_LOCAL, "PK_ROLE_ENUM_GET_DETAILS_LOCAL", "get-details-local" },
            { PK_ROLE_ENUM_GET_FILES_LOCAL, "PK_ROLE_ENUM_GET_FILES_LOCAL", "get-files-local" },
            { PK_ROLE_ENUM_REPO_REMOVE, "PK_ROLE_ENUM_REPO_REMOVE", "repo-remove" },
            { PK_ROLE_ENUM_LAST, "PK_ROLE_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkRoleEnum"), values);
    }
    return etype;
}

GType pk_status_enum_get_type (void) G_GNUC_CONST;

GType
pk_status_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_STATUS_ENUM_UNKNOWN, "PK_STATUS_ENUM_UNKNOWN", "unknown" },
            { PK_STATUS_ENUM_WAIT, "PK_STATUS_ENUM_WAIT", "wait" },
            { PK_STATUS_ENUM_SETUP, "PK_STATUS_ENUM_SETUP", "setup" },
            { PK_STATUS_ENUM_RUNNING, "PK_STATUS_ENUM_RUNNING", "running" },
            { PK_STATUS_ENUM_QUERY, "PK_STATUS_ENUM_QUERY", "query" },
            { PK_STATUS_ENUM_INFO, "PK_STATUS_ENUM_INFO", "info" },
            { PK_STATUS_ENUM_REMOVE, "PK_STATUS_ENUM_REMOVE", "remove" },
            { PK_STATUS_ENUM_REFRESH_CACHE, "PK_STATUS_ENUM_REFRESH_CACHE", "refresh-cache" },
            { PK_STATUS_ENUM_DOWNLOAD, "PK_STATUS_ENUM_DOWNLOAD", "download" },
            { PK_STATUS_ENUM_INSTALL, "PK_STATUS_ENUM_INSTALL", "install" },
            { PK_STATUS_ENUM_UPDATE, "PK_STATUS_ENUM_UPDATE", "update" },
            { PK_STATUS_ENUM_CLEANUP, "PK_STATUS_ENUM_CLEANUP", "cleanup" },
            { PK_STATUS_ENUM_OBSOLETE, "PK_STATUS_ENUM_OBSOLETE", "obsolete" },
            { PK_STATUS_ENUM_DEP_RESOLVE, "PK_STATUS_ENUM_DEP_RESOLVE", "dep-resolve" },
            { PK_STATUS_ENUM_SIG_CHECK, "PK_STATUS_ENUM_SIG_CHECK", "sig-check" },
            { PK_STATUS_ENUM_TEST_COMMIT, "PK_STATUS_ENUM_TEST_COMMIT", "test-commit" },
            { PK_STATUS_ENUM_COMMIT, "PK_STATUS_ENUM_COMMIT", "commit" },
            { PK_STATUS_ENUM_REQUEST, "PK_STATUS_ENUM_REQUEST", "request" },
            { PK_STATUS_ENUM_FINISHED, "PK_STATUS_ENUM_FINISHED", "finished" },
            { PK_STATUS_ENUM_CANCEL, "PK_STATUS_ENUM_CANCEL", "cancel" },
            { PK_STATUS_ENUM_DOWNLOAD_REPOSITORY, "PK_STATUS_ENUM_DOWNLOAD_REPOSITORY", "download-repository" },
            { PK_STATUS_ENUM_DOWNLOAD_PACKAGELIST, "PK_STATUS_ENUM_DOWNLOAD_PACKAGELIST", "download-packagelist" },
            { PK_STATUS_ENUM_DOWNLOAD_FILELIST, "PK_STATUS_ENUM_DOWNLOAD_FILELIST", "download-filelist" },
            { PK_STATUS_ENUM_DOWNLOAD_CHANGELOG, "PK_STATUS_ENUM_DOWNLOAD_CHANGELOG", "download-changelog" },
            { PK_STATUS_ENUM_DOWNLOAD_GROUP, "PK_STATUS_ENUM_DOWNLOAD_GROUP", "download-group" },
            { PK_STATUS_ENUM_DOWNLOAD_UPDATEINFO, "PK_STATUS_ENUM_DOWNLOAD_UPDATEINFO", "download-updateinfo" },
            { PK_STATUS_ENUM_REPACKAGING, "PK_STATUS_ENUM_REPACKAGING", "repackaging" },
            { PK_STATUS_ENUM_LOADING_CACHE, "PK_STATUS_ENUM_LOADING_CACHE", "loading-cache" },
            { PK_STATUS_ENUM_SCAN_APPLICATIONS, "PK_STATUS_ENUM_SCAN_APPLICATIONS", "scan-applications" },
            { PK_STATUS_ENUM_GENERATE_PACKAGE_LIST, "PK_STATUS_ENUM_GENERATE_PACKAGE_LIST", "generate-package-list" },
            { PK_STATUS_ENUM_WAITING_FOR_LOCK, "PK_STATUS_ENUM_WAITING_FOR_LOCK", "waiting-for-lock" },
            { PK_STATUS_ENUM_WAITING_FOR_AUTH, "PK_STATUS_ENUM_WAITING_FOR_AUTH", "waiting-for-auth" },
            { PK_STATUS_ENUM_SCAN_PROCESS_LIST, "PK_STATUS_ENUM_SCAN_PROCESS_LIST", "scan-process-list" },
            { PK_STATUS_ENUM_CHECK_EXECUTABLE_FILES, "PK_STATUS_ENUM_CHECK_EXECUTABLE_FILES", "check-executable-files" },
            { PK_STATUS_ENUM_CHECK_LIBRARIES, "PK_STATUS_ENUM_CHECK_LIBRARIES", "check-libraries" },
            { PK_STATUS_ENUM_COPY_FILES, "PK_STATUS_ENUM_COPY_FILES", "copy-files" },
            { PK_STATUS_ENUM_LAST, "PK_STATUS_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkStatusEnum"), values);
    }
    return etype;
}

GType pk_exit_enum_get_type (void) G_GNUC_CONST;

GType
pk_exit_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_EXIT_ENUM_UNKNOWN, "PK_EXIT_ENUM_UNKNOWN", "unknown" },
            { PK_EXIT_ENUM_SUCCESS, "PK_EXIT_ENUM_SUCCESS", "success" },
            { PK_EXIT_ENUM_FAILED, "PK_EXIT_ENUM_FAILED", "failed" },
            { PK_EXIT_ENUM_CANCELLED, "PK_EXIT_ENUM_CANCELLED", "cancelled" },
            { PK_EXIT_ENUM_KEY_REQUIRED, "PK_EXIT_ENUM_KEY_REQUIRED", "key-required" },
            { PK_EXIT_ENUM_EULA_REQUIRED, "PK_EXIT_ENUM_EULA_REQUIRED", "eula-required" },
            { PK_EXIT_ENUM_KILLED, "PK_EXIT_ENUM_KILLED", "killed" },
            { PK_EXIT_ENUM_MEDIA_CHANGE_REQUIRED, "PK_EXIT_ENUM_MEDIA_CHANGE_REQUIRED", "media-change-required" },
            { PK_EXIT_ENUM_NEED_UNTRUSTED, "PK_EXIT_ENUM_NEED_UNTRUSTED", "need-untrusted" },
            { PK_EXIT_ENUM_CANCELLED_PRIORITY, "PK_EXIT_ENUM_CANCELLED_PRIORITY", "cancelled-priority" },
            { PK_EXIT_ENUM_SKIP_TRANSACTION, "PK_EXIT_ENUM_SKIP_TRANSACTION", "skip-transaction" },
            { PK_EXIT_ENUM_REPAIR_REQUIRED, "PK_EXIT_ENUM_REPAIR_REQUIRED", "repair-required" },
            { PK_EXIT_ENUM_LAST, "PK_EXIT_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkExitEnum"), values);
    }
    return etype;
}

GType pk_network_enum_get_type (void) G_GNUC_CONST;

GType
pk_network_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_NETWORK_ENUM_UNKNOWN, "PK_NETWORK_ENUM_UNKNOWN", "unknown" },
            { PK_NETWORK_ENUM_OFFLINE, "PK_NETWORK_ENUM_OFFLINE", "offline" },
            { PK_NETWORK_ENUM_ONLINE, "PK_NETWORK_ENUM_ONLINE", "online" },
            { PK_NETWORK_ENUM_WIRED, "PK_NETWORK_ENUM_WIRED", "wired" },
            { PK_NETWORK_ENUM_WIFI, "PK_NETWORK_ENUM_WIFI", "wifi" },
            { PK_NETWORK_ENUM_MOBILE, "PK_NETWORK_ENUM_MOBILE", "mobile" },
            { PK_NETWORK_ENUM_LAST, "PK_NETWORK_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkNetworkEnum"), values);
    }
    return etype;
}

GType pk_filter_enum_get_type (void) G_GNUC_CONST;

GType
pk_filter_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_FILTER_ENUM_UNKNOWN, "PK_FILTER_ENUM_UNKNOWN", "unknown" },
            { PK_FILTER_ENUM_NONE, "PK_FILTER_ENUM_NONE", "none" },
            { PK_FILTER_ENUM_INSTALLED, "PK_FILTER_ENUM_INSTALLED", "installed" },
            { PK_FILTER_ENUM_NOT_INSTALLED, "PK_FILTER_ENUM_NOT_INSTALLED", "not-installed" },
            { PK_FILTER_ENUM_DEVELOPMENT, "PK_FILTER_ENUM_DEVELOPMENT", "development" },
            { PK_FILTER_ENUM_NOT_DEVELOPMENT, "PK_FILTER_ENUM_NOT_DEVELOPMENT", "not-development" },
            { PK_FILTER_ENUM_GUI, "PK_FILTER_ENUM_GUI", "gui" },
            { PK_FILTER_ENUM_NOT_GUI, "PK_FILTER_ENUM_NOT_GUI", "not-gui" },
            { PK_FILTER_ENUM_FREE, "PK_FILTER_ENUM_FREE", "free" },
            { PK_FILTER_ENUM_NOT_FREE, "PK_FILTER_ENUM_NOT_FREE", "not-free" },
            { PK_FILTER_ENUM_VISIBLE, "PK_FILTER_ENUM_VISIBLE", "visible" },
            { PK_FILTER_ENUM_NOT_VISIBLE, "PK_FILTER_ENUM_NOT_VISIBLE", "not-visible" },
            { PK_FILTER_ENUM_SUPPORTED, "PK_FILTER_ENUM_SUPPORTED", "supported" },
            { PK_FILTER_ENUM_NOT_SUPPORTED, "PK_FILTER_ENUM_NOT_SUPPORTED", "not-supported" },
            { PK_FILTER_ENUM_BASENAME, "PK_FILTER_ENUM_BASENAME", "basename" },
            { PK_FILTER_ENUM_NOT_BASENAME, "PK_FILTER_ENUM_NOT_BASENAME", "not-basename" },
            { PK_FILTER_ENUM_NEWEST, "PK_FILTER_ENUM_NEWEST", "newest" },
            { PK_FILTER_ENUM_NOT_NEWEST, "PK_FILTER_ENUM_NOT_NEWEST", "not-newest" },
            { PK_FILTER_ENUM_ARCH, "PK_FILTER_ENUM_ARCH", "arch" },
            { PK_FILTER_ENUM_NOT_ARCH, "PK_FILTER_ENUM_NOT_ARCH", "not-arch" },
            { PK_FILTER_ENUM_SOURCE, "PK_FILTER_ENUM_SOURCE", "source" },
            { PK_FILTER_ENUM_NOT_SOURCE, "PK_FILTER_ENUM_NOT_SOURCE", "not-source" },
            { PK_FILTER_ENUM_COLLECTIONS, "PK_FILTER_ENUM_COLLECTIONS", "collections" },
            { PK_FILTER_ENUM_NOT_COLLECTIONS, "PK_FILTER_ENUM_NOT_COLLECTIONS", "not-collections" },
            { PK_FILTER_ENUM_APPLICATION, "PK_FILTER_ENUM_APPLICATION", "application" },
            { PK_FILTER_ENUM_NOT_APPLICATION, "PK_FILTER_ENUM_NOT_APPLICATION", "not-application" },
            { PK_FILTER_ENUM_DOWNLOADED, "PK_FILTER_ENUM_DOWNLOADED", "downloaded" },
            { PK_FILTER_ENUM_NOT_DOWNLOADED, "PK_FILTER_ENUM_NOT_DOWNLOADED", "not-downloaded" },
            { PK_FILTER_ENUM_LAST, "PK_FILTER_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkFilterEnum"), values);
    }
    return etype;
}

GType pk_restart_enum_get_type (void) G_GNUC_CONST;

GType
pk_restart_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_RESTART_ENUM_UNKNOWN, "PK_RESTART_ENUM_UNKNOWN", "unknown" },
            { PK_RESTART_ENUM_NONE, "PK_RESTART_ENUM_NONE", "none" },
            { PK_RESTART_ENUM_APPLICATION, "PK_RESTART_ENUM_APPLICATION", "application" },
            { PK_RESTART_ENUM_SESSION, "PK_RESTART_ENUM_SESSION", "session" },
            { PK_RESTART_ENUM_SYSTEM, "PK_RESTART_ENUM_SYSTEM", "system" },
            { PK_RESTART_ENUM_SECURITY_SESSION, "PK_RESTART_ENUM_SECURITY_SESSION", "security-session" },
            { PK_RESTART_ENUM_SECURITY_SYSTEM, "PK_RESTART_ENUM_SECURITY_SYSTEM", "security-system" },
            { PK_RESTART_ENUM_LAST, "PK_RESTART_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkRestartEnum"), values);
    }
    return etype;
}

GType pk_error_enum_get_type (void) G_GNUC_CONST;

GType
pk_error_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_ERROR_ENUM_UNKNOWN, "PK_ERROR_ENUM_UNKNOWN", "unknown" },
            { PK_ERROR_ENUM_OOM, "PK_ERROR_ENUM_OOM", "oom" },
            { PK_ERROR_ENUM_NO_NETWORK, "PK_ERROR_ENUM_NO_NETWORK", "no-network" },
            { PK_ERROR_ENUM_NOT_SUPPORTED, "PK_ERROR_ENUM_NOT_SUPPORTED", "not-supported" },
            { PK_ERROR_ENUM_INTERNAL_ERROR, "PK_ERROR_ENUM_INTERNAL_ERROR", "internal-error" },
            { PK_ERROR_ENUM_GPG_FAILURE, "PK_ERROR_ENUM_GPG_FAILURE", "gpg-failure" },
            { PK_ERROR_ENUM_PACKAGE_ID_INVALID, "PK_ERROR_ENUM_PACKAGE_ID_INVALID", "package-id-invalid" },
            { PK_ERROR_ENUM_PACKAGE_NOT_INSTALLED, "PK_ERROR_ENUM_PACKAGE_NOT_INSTALLED", "package-not-installed" },
            { PK_ERROR_ENUM_PACKAGE_NOT_FOUND, "PK_ERROR_ENUM_PACKAGE_NOT_FOUND", "package-not-found" },
            { PK_ERROR_ENUM_PACKAGE_ALREADY_INSTALLED, "PK_ERROR_ENUM_PACKAGE_ALREADY_INSTALLED", "package-already-installed" },
            { PK_ERROR_ENUM_PACKAGE_DOWNLOAD_FAILED, "PK_ERROR_ENUM_PACKAGE_DOWNLOAD_FAILED", "package-download-failed" },
            { PK_ERROR_ENUM_GROUP_NOT_FOUND, "PK_ERROR_ENUM_GROUP_NOT_FOUND", "group-not-found" },
            { PK_ERROR_ENUM_GROUP_LIST_INVALID, "PK_ERROR_ENUM_GROUP_LIST_INVALID", "group-list-invalid" },
            { PK_ERROR_ENUM_DEP_RESOLUTION_FAILED, "PK_ERROR_ENUM_DEP_RESOLUTION_FAILED", "dep-resolution-failed" },
            { PK_ERROR_ENUM_FILTER_INVALID, "PK_ERROR_ENUM_FILTER_INVALID", "filter-invalid" },
            { PK_ERROR_ENUM_CREATE_THREAD_FAILED, "PK_ERROR_ENUM_CREATE_THREAD_FAILED", "create-thread-failed" },
            { PK_ERROR_ENUM_TRANSACTION_ERROR, "PK_ERROR_ENUM_TRANSACTION_ERROR", "transaction-error" },
            { PK_ERROR_ENUM_TRANSACTION_CANCELLED, "PK_ERROR_ENUM_TRANSACTION_CANCELLED", "transaction-cancelled" },
            { PK_ERROR_ENUM_NO_CACHE, "PK_ERROR_ENUM_NO_CACHE", "no-cache" },
            { PK_ERROR_ENUM_REPO_NOT_FOUND, "PK_ERROR_ENUM_REPO_NOT_FOUND", "repo-not-found" },
            { PK_ERROR_ENUM_CANNOT_REMOVE_SYSTEM_PACKAGE, "PK_ERROR_ENUM_CANNOT_REMOVE_SYSTEM_PACKAGE", "cannot-remove-system-package" },
            { PK_ERROR_ENUM_PROCESS_KILL, "PK_ERROR_ENUM_PROCESS_KILL", "process-kill" },
            { PK_ERROR_ENUM_FAILED_INITIALIZATION, "PK_ERROR_ENUM_FAILED_INITIALIZATION", "failed-initialization" },
            { PK_ERROR_ENUM_FAILED_FINALISE, "PK_ERROR_ENUM_FAILED_FINALISE", "failed-finalise" },
            { PK_ERROR_ENUM_FAILED_CONFIG_PARSING, "PK_ERROR_ENUM_FAILED_CONFIG_PARSING", "failed-config-parsing" },
            { PK_ERROR_ENUM_CANNOT_CANCEL, "PK_ERROR_ENUM_CANNOT_CANCEL", "cannot-cancel" },
            { PK_ERROR_ENUM_CANNOT_GET_LOCK, "PK_ERROR_ENUM_CANNOT_GET_LOCK", "cannot-get-lock" },
            { PK_ERROR_ENUM_NO_PACKAGES_TO_UPDATE, "PK_ERROR_ENUM_NO_PACKAGES_TO_UPDATE", "no-packages-to-update" },
            { PK_ERROR_ENUM_CANNOT_WRITE_REPO_CONFIG, "PK_ERROR_ENUM_CANNOT_WRITE_REPO_CONFIG", "cannot-write-repo-config" },
            { PK_ERROR_ENUM_LOCAL_INSTALL_FAILED, "PK_ERROR_ENUM_LOCAL_INSTALL_FAILED", "local-install-failed" },
            { PK_ERROR_ENUM_BAD_GPG_SIGNATURE, "PK_ERROR_ENUM_BAD_GPG_SIGNATURE", "bad-gpg-signature" },
            { PK_ERROR_ENUM_MISSING_GPG_SIGNATURE, "PK_ERROR_ENUM_MISSING_GPG_SIGNATURE", "missing-gpg-signature" },
            { PK_ERROR_ENUM_CANNOT_INSTALL_SOURCE_PACKAGE, "PK_ERROR_ENUM_CANNOT_INSTALL_SOURCE_PACKAGE", "cannot-install-source-package" },
            { PK_ERROR_ENUM_REPO_CONFIGURATION_ERROR, "PK_ERROR_ENUM_REPO_CONFIGURATION_ERROR", "repo-configuration-error" },
            { PK_ERROR_ENUM_NO_LICENSE_AGREEMENT, "PK_ERROR_ENUM_NO_LICENSE_AGREEMENT", "no-license-agreement" },
            { PK_ERROR_ENUM_FILE_CONFLICTS, "PK_ERROR_ENUM_FILE_CONFLICTS", "file-conflicts" },
            { PK_ERROR_ENUM_PACKAGE_CONFLICTS, "PK_ERROR_ENUM_PACKAGE_CONFLICTS", "package-conflicts" },
            { PK_ERROR_ENUM_REPO_NOT_AVAILABLE, "PK_ERROR_ENUM_REPO_NOT_AVAILABLE", "repo-not-available" },
            { PK_ERROR_ENUM_INVALID_PACKAGE_FILE, "PK_ERROR_ENUM_INVALID_PACKAGE_FILE", "invalid-package-file" },
            { PK_ERROR_ENUM_PACKAGE_INSTALL_BLOCKED, "PK_ERROR_ENUM_PACKAGE_INSTALL_BLOCKED", "package-install-blocked" },
            { PK_ERROR_ENUM_PACKAGE_CORRUPT, "PK_ERROR_ENUM_PACKAGE_CORRUPT", "package-corrupt" },
            { PK_ERROR_ENUM_ALL_PACKAGES_ALREADY_INSTALLED, "PK_ERROR_ENUM_ALL_PACKAGES_ALREADY_INSTALLED", "all-packages-already-installed" },
            { PK_ERROR_ENUM_FILE_NOT_FOUND, "PK_ERROR_ENUM_FILE_NOT_FOUND", "file-not-found" },
            { PK_ERROR_ENUM_NO_MORE_MIRRORS_TO_TRY, "PK_ERROR_ENUM_NO_MORE_MIRRORS_TO_TRY", "no-more-mirrors-to-try" },
            { PK_ERROR_ENUM_NO_DISTRO_UPGRADE_DATA, "PK_ERROR_ENUM_NO_DISTRO_UPGRADE_DATA", "no-distro-upgrade-data" },
            { PK_ERROR_ENUM_INCOMPATIBLE_ARCHITECTURE, "PK_ERROR_ENUM_INCOMPATIBLE_ARCHITECTURE", "incompatible-architecture" },
            { PK_ERROR_ENUM_NO_SPACE_ON_DEVICE, "PK_ERROR_ENUM_NO_SPACE_ON_DEVICE", "no-space-on-device" },
            { PK_ERROR_ENUM_MEDIA_CHANGE_REQUIRED, "PK_ERROR_ENUM_MEDIA_CHANGE_REQUIRED", "media-change-required" },
            { PK_ERROR_ENUM_NOT_AUTHORIZED, "PK_ERROR_ENUM_NOT_AUTHORIZED", "not-authorized" },
            { PK_ERROR_ENUM_UPDATE_NOT_FOUND, "PK_ERROR_ENUM_UPDATE_NOT_FOUND", "update-not-found" },
            { PK_ERROR_ENUM_CANNOT_INSTALL_REPO_UNSIGNED, "PK_ERROR_ENUM_CANNOT_INSTALL_REPO_UNSIGNED", "cannot-install-repo-unsigned" },
            { PK_ERROR_ENUM_CANNOT_UPDATE_REPO_UNSIGNED, "PK_ERROR_ENUM_CANNOT_UPDATE_REPO_UNSIGNED", "cannot-update-repo-unsigned" },
            { PK_ERROR_ENUM_CANNOT_GET_FILELIST, "PK_ERROR_ENUM_CANNOT_GET_FILELIST", "cannot-get-filelist" },
            { PK_ERROR_ENUM_CANNOT_GET_REQUIRES, "PK_ERROR_ENUM_CANNOT_GET_REQUIRES", "cannot-get-requires" },
            { PK_ERROR_ENUM_CANNOT_DISABLE_REPOSITORY, "PK_ERROR_ENUM_CANNOT_DISABLE_REPOSITORY", "cannot-disable-repository" },
            { PK_ERROR_ENUM_RESTRICTED_DOWNLOAD, "PK_ERROR_ENUM_RESTRICTED_DOWNLOAD", "restricted-download" },
            { PK_ERROR_ENUM_PACKAGE_FAILED_TO_CONFIGURE, "PK_ERROR_ENUM_PACKAGE_FAILED_TO_CONFIGURE", "package-failed-to-configure" },
            { PK_ERROR_ENUM_PACKAGE_FAILED_TO_BUILD, "PK_ERROR_ENUM_PACKAGE_FAILED_TO_BUILD", "package-failed-to-build" },
            { PK_ERROR_ENUM_PACKAGE_FAILED_TO_INSTALL, "PK_ERROR_ENUM_PACKAGE_FAILED_TO_INSTALL", "package-failed-to-install" },
            { PK_ERROR_ENUM_PACKAGE_FAILED_TO_REMOVE, "PK_ERROR_ENUM_PACKAGE_FAILED_TO_REMOVE", "package-failed-to-remove" },
            { PK_ERROR_ENUM_UPDATE_FAILED_DUE_TO_RUNNING_PROCESS, "PK_ERROR_ENUM_UPDATE_FAILED_DUE_TO_RUNNING_PROCESS", "update-failed-due-to-running-process" },
            { PK_ERROR_ENUM_PACKAGE_DATABASE_CHANGED, "PK_ERROR_ENUM_PACKAGE_DATABASE_CHANGED", "package-database-changed" },
            { PK_ERROR_ENUM_PROVIDE_TYPE_NOT_SUPPORTED, "PK_ERROR_ENUM_PROVIDE_TYPE_NOT_SUPPORTED", "provide-type-not-supported" },
            { PK_ERROR_ENUM_INSTALL_ROOT_INVALID, "PK_ERROR_ENUM_INSTALL_ROOT_INVALID", "install-root-invalid" },
            { PK_ERROR_ENUM_CANNOT_FETCH_SOURCES, "PK_ERROR_ENUM_CANNOT_FETCH_SOURCES", "cannot-fetch-sources" },
            { PK_ERROR_ENUM_CANCELLED_PRIORITY, "PK_ERROR_ENUM_CANCELLED_PRIORITY", "cancelled-priority" },
            { PK_ERROR_ENUM_UNFINISHED_TRANSACTION, "PK_ERROR_ENUM_UNFINISHED_TRANSACTION", "unfinished-transaction" },
            { PK_ERROR_ENUM_LOCK_REQUIRED, "PK_ERROR_ENUM_LOCK_REQUIRED", "lock-required" },
            { PK_ERROR_ENUM_LAST, "PK_ERROR_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkErrorEnum"), values);
    }
    return etype;
}

GType pk_group_enum_get_type (void) G_GNUC_CONST;

GType
pk_group_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_GROUP_ENUM_UNKNOWN, "PK_GROUP_ENUM_UNKNOWN", "unknown" },
            { PK_GROUP_ENUM_ACCESSIBILITY, "PK_GROUP_ENUM_ACCESSIBILITY", "accessibility" },
            { PK_GROUP_ENUM_ACCESSORIES, "PK_GROUP_ENUM_ACCESSORIES", "accessories" },
            { PK_GROUP_ENUM_ADMIN_TOOLS, "PK_GROUP_ENUM_ADMIN_TOOLS", "admin-tools" },
            { PK_GROUP_ENUM_COMMUNICATION, "PK_GROUP_ENUM_COMMUNICATION", "communication" },
            { PK_GROUP_ENUM_DESKTOP_GNOME, "PK_GROUP_ENUM_DESKTOP_GNOME", "desktop-gnome" },
            { PK_GROUP_ENUM_DESKTOP_KDE, "PK_GROUP_ENUM_DESKTOP_KDE", "desktop-kde" },
            { PK_GROUP_ENUM_DESKTOP_OTHER, "PK_GROUP_ENUM_DESKTOP_OTHER", "desktop-other" },
            { PK_GROUP_ENUM_DESKTOP_XFCE, "PK_GROUP_ENUM_DESKTOP_XFCE", "desktop-xfce" },
            { PK_GROUP_ENUM_EDUCATION, "PK_GROUP_ENUM_EDUCATION", "education" },
            { PK_GROUP_ENUM_FONTS, "PK_GROUP_ENUM_FONTS", "fonts" },
            { PK_GROUP_ENUM_GAMES, "PK_GROUP_ENUM_GAMES", "games" },
            { PK_GROUP_ENUM_GRAPHICS, "PK_GROUP_ENUM_GRAPHICS", "graphics" },
            { PK_GROUP_ENUM_INTERNET, "PK_GROUP_ENUM_INTERNET", "internet" },
            { PK_GROUP_ENUM_LEGACY, "PK_GROUP_ENUM_LEGACY", "legacy" },
            { PK_GROUP_ENUM_LOCALIZATION, "PK_GROUP_ENUM_LOCALIZATION", "localization" },
            { PK_GROUP_ENUM_MAPS, "PK_GROUP_ENUM_MAPS", "maps" },
            { PK_GROUP_ENUM_MULTIMEDIA, "PK_GROUP_ENUM_MULTIMEDIA", "multimedia" },
            { PK_GROUP_ENUM_NETWORK, "PK_GROUP_ENUM_NETWORK", "network" },
            { PK_GROUP_ENUM_OFFICE, "PK_GROUP_ENUM_OFFICE", "office" },
            { PK_GROUP_ENUM_OTHER, "PK_GROUP_ENUM_OTHER", "other" },
            { PK_GROUP_ENUM_POWER_MANAGEMENT, "PK_GROUP_ENUM_POWER_MANAGEMENT", "power-management" },
            { PK_GROUP_ENUM_PROGRAMMING, "PK_GROUP_ENUM_PROGRAMMING", "programming" },
            { PK_GROUP_ENUM_PUBLISHING, "PK_GROUP_ENUM_PUBLISHING", "publishing" },
            { PK_GROUP_ENUM_REPOS, "PK_GROUP_ENUM_REPOS", "repos" },
            { PK_GROUP_ENUM_SECURITY, "PK_GROUP_ENUM_SECURITY", "security" },
            { PK_GROUP_ENUM_SERVERS, "PK_GROUP_ENUM_SERVERS", "servers" },
            { PK_GROUP_ENUM_SYSTEM, "PK_GROUP_ENUM_SYSTEM", "system" },
            { PK_GROUP_ENUM_VIRTUALIZATION, "PK_GROUP_ENUM_VIRTUALIZATION", "virtualization" },
            { PK_GROUP_ENUM_SCIENCE, "PK_GROUP_ENUM_SCIENCE", "science" },
            { PK_GROUP_ENUM_DOCUMENTATION, "PK_GROUP_ENUM_DOCUMENTATION", "documentation" },
            { PK_GROUP_ENUM_ELECTRONICS, "PK_GROUP_ENUM_ELECTRONICS", "electronics" },
            { PK_GROUP_ENUM_COLLECTIONS, "PK_GROUP_ENUM_COLLECTIONS", "collections" },
            { PK_GROUP_ENUM_VENDOR, "PK_GROUP_ENUM_VENDOR", "vendor" },
            { PK_GROUP_ENUM_NEWEST, "PK_GROUP_ENUM_NEWEST", "newest" },
            { PK_GROUP_ENUM_LAST, "PK_GROUP_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkGroupEnum"), values);
    }
    return etype;
}

GType pk_update_state_enum_get_type (void) G_GNUC_CONST;

GType
pk_update_state_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_UPDATE_STATE_ENUM_UNKNOWN, "PK_UPDATE_STATE_ENUM_UNKNOWN", "unknown" },
            { PK_UPDATE_STATE_ENUM_STABLE, "PK_UPDATE_STATE_ENUM_STABLE", "stable" },
            { PK_UPDATE_STATE_ENUM_UNSTABLE, "PK_UPDATE_STATE_ENUM_UNSTABLE", "unstable" },
            { PK_UPDATE_STATE_ENUM_TESTING, "PK_UPDATE_STATE_ENUM_TESTING", "testing" },
            { PK_UPDATE_STATE_ENUM_LAST, "PK_UPDATE_STATE_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkUpdateStateEnum"), values);
    }
    return etype;
}

GType pk_info_enum_get_type (void) G_GNUC_CONST;

GType
pk_info_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_INFO_ENUM_UNKNOWN, "PK_INFO_ENUM_UNKNOWN", "unknown" },
            { PK_INFO_ENUM_INSTALLED, "PK_INFO_ENUM_INSTALLED", "installed" },
            { PK_INFO_ENUM_AVAILABLE, "PK_INFO_ENUM_AVAILABLE", "available" },
            { PK_INFO_ENUM_LOW, "PK_INFO_ENUM_LOW", "low" },
            { PK_INFO_ENUM_ENHANCEMENT, "PK_INFO_ENUM_ENHANCEMENT", "enhancement" },
            { PK_INFO_ENUM_NORMAL, "PK_INFO_ENUM_NORMAL", "normal" },
            { PK_INFO_ENUM_BUGFIX, "PK_INFO_ENUM_BUGFIX", "bugfix" },
            { PK_INFO_ENUM_IMPORTANT, "PK_INFO_ENUM_IMPORTANT", "important" },
            { PK_INFO_ENUM_SECURITY, "PK_INFO_ENUM_SECURITY", "security" },
            { PK_INFO_ENUM_BLOCKED, "PK_INFO_ENUM_BLOCKED", "blocked" },
            { PK_INFO_ENUM_DOWNLOADING, "PK_INFO_ENUM_DOWNLOADING", "downloading" },
            { PK_INFO_ENUM_UPDATING, "PK_INFO_ENUM_UPDATING", "updating" },
            { PK_INFO_ENUM_INSTALLING, "PK_INFO_ENUM_INSTALLING", "installing" },
            { PK_INFO_ENUM_REMOVING, "PK_INFO_ENUM_REMOVING", "removing" },
            { PK_INFO_ENUM_CLEANUP, "PK_INFO_ENUM_CLEANUP", "cleanup" },
            { PK_INFO_ENUM_OBSOLETING, "PK_INFO_ENUM_OBSOLETING", "obsoleting" },
            { PK_INFO_ENUM_COLLECTION_INSTALLED, "PK_INFO_ENUM_COLLECTION_INSTALLED", "collection-installed" },
            { PK_INFO_ENUM_COLLECTION_AVAILABLE, "PK_INFO_ENUM_COLLECTION_AVAILABLE", "collection-available" },
            { PK_INFO_ENUM_FINISHED, "PK_INFO_ENUM_FINISHED", "finished" },
            { PK_INFO_ENUM_REINSTALLING, "PK_INFO_ENUM_REINSTALLING", "reinstalling" },
            { PK_INFO_ENUM_DOWNGRADING, "PK_INFO_ENUM_DOWNGRADING", "downgrading" },
            { PK_INFO_ENUM_PREPARING, "PK_INFO_ENUM_PREPARING", "preparing" },
            { PK_INFO_ENUM_DECOMPRESSING, "PK_INFO_ENUM_DECOMPRESSING", "decompressing" },
            { PK_INFO_ENUM_UNTRUSTED, "PK_INFO_ENUM_UNTRUSTED", "untrusted" },
            { PK_INFO_ENUM_TRUSTED, "PK_INFO_ENUM_TRUSTED", "trusted" },
            { PK_INFO_ENUM_LAST, "PK_INFO_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkInfoEnum"), values);
    }
    return etype;
}

GType pk_distro_upgrade_enum_get_type (void) G_GNUC_CONST;

GType
pk_distro_upgrade_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_DISTRO_UPGRADE_ENUM_UNKNOWN, "PK_DISTRO_UPGRADE_ENUM_UNKNOWN", "unknown" },
            { PK_DISTRO_UPGRADE_ENUM_STABLE, "PK_DISTRO_UPGRADE_ENUM_STABLE", "stable" },
            { PK_DISTRO_UPGRADE_ENUM_UNSTABLE, "PK_DISTRO_UPGRADE_ENUM_UNSTABLE", "unstable" },
            { PK_DISTRO_UPGRADE_ENUM_LAST, "PK_DISTRO_UPGRADE_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkDistroUpgradeEnum"), values);
    }
    return etype;
}

GType pk_sig_type_enum_get_type (void) G_GNUC_CONST;

GType
pk_sig_type_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_SIGTYPE_ENUM_UNKNOWN, "PK_SIGTYPE_ENUM_UNKNOWN", "unknown" },
            { PK_SIGTYPE_ENUM_GPG, "PK_SIGTYPE_ENUM_GPG", "gpg" },
            { PK_SIGTYPE_ENUM_LAST, "PK_SIGTYPE_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkSigTypeEnum"), values);
    }
    return etype;
}

GType pk_media_type_enum_get_type (void) G_GNUC_CONST;

GType
pk_media_type_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_MEDIA_TYPE_ENUM_UNKNOWN, "PK_MEDIA_TYPE_ENUM_UNKNOWN", "unknown" },
            { PK_MEDIA_TYPE_ENUM_CD, "PK_MEDIA_TYPE_ENUM_CD", "cd" },
            { PK_MEDIA_TYPE_ENUM_DVD, "PK_MEDIA_TYPE_ENUM_DVD", "dvd" },
            { PK_MEDIA_TYPE_ENUM_DISC, "PK_MEDIA_TYPE_ENUM_DISC", "disc" },
            { PK_MEDIA_TYPE_ENUM_LAST, "PK_MEDIA_TYPE_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkMediaTypeEnum"), values);
    }
    return etype;
}

GType pk_authorize_enum_get_type (void) G_GNUC_CONST;

GType
pk_authorize_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_AUTHORIZE_ENUM_UNKNOWN, "PK_AUTHORIZE_ENUM_UNKNOWN", "unknown" },
            { PK_AUTHORIZE_ENUM_YES, "PK_AUTHORIZE_ENUM_YES", "yes" },
            { PK_AUTHORIZE_ENUM_NO, "PK_AUTHORIZE_ENUM_NO", "no" },
            { PK_AUTHORIZE_ENUM_INTERACTIVE, "PK_AUTHORIZE_ENUM_INTERACTIVE", "interactive" },
            { PK_AUTHORIZE_ENUM_LAST, "PK_AUTHORIZE_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkAuthorizeEnum"), values);
    }
    return etype;
}

GType pk_upgrade_kind_enum_get_type (void) G_GNUC_CONST;

GType
pk_upgrade_kind_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_UPGRADE_KIND_ENUM_UNKNOWN, "PK_UPGRADE_KIND_ENUM_UNKNOWN", "unknown" },
            { PK_UPGRADE_KIND_ENUM_MINIMAL, "PK_UPGRADE_KIND_ENUM_MINIMAL", "minimal" },
            { PK_UPGRADE_KIND_ENUM_DEFAULT, "PK_UPGRADE_KIND_ENUM_DEFAULT", "default" },
            { PK_UPGRADE_KIND_ENUM_COMPLETE, "PK_UPGRADE_KIND_ENUM_COMPLETE", "complete" },
            { PK_UPGRADE_KIND_ENUM_LAST, "PK_UPGRADE_KIND_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkUpgradeKindEnum"), values);
    }
    return etype;
}

GType pk_transaction_flag_enum_get_type (void) G_GNUC_CONST;

GType
pk_transaction_flag_enum_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_TRANSACTION_FLAG_ENUM_NONE, "PK_TRANSACTION_FLAG_ENUM_NONE", "none" },
            { PK_TRANSACTION_FLAG_ENUM_ONLY_TRUSTED, "PK_TRANSACTION_FLAG_ENUM_ONLY_TRUSTED", "only-trusted" },
            { PK_TRANSACTION_FLAG_ENUM_SIMULATE, "PK_TRANSACTION_FLAG_ENUM_SIMULATE", "simulate" },
            { PK_TRANSACTION_FLAG_ENUM_ONLY_DOWNLOAD, "PK_TRANSACTION_FLAG_ENUM_ONLY_DOWNLOAD", "only-download" },
            { PK_TRANSACTION_FLAG_ENUM_LAST, "PK_TRANSACTION_FLAG_ENUM_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkTransactionFlagEnum"), values);
    }
    return etype;
}

#include "pk-offline.h"
/* enumerations from "pk-offline.h" */
GType pk_offline_action_get_type (void) G_GNUC_CONST;

GType
pk_offline_action_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_OFFLINE_ACTION_UNKNOWN, "PK_OFFLINE_ACTION_UNKNOWN", "unknown" },
            { PK_OFFLINE_ACTION_REBOOT, "PK_OFFLINE_ACTION_REBOOT", "reboot" },
            { PK_OFFLINE_ACTION_POWER_OFF, "PK_OFFLINE_ACTION_POWER_OFF", "power-off" },
            { PK_OFFLINE_ACTION_UNSET, "PK_OFFLINE_ACTION_UNSET", "unset" },
            { PK_OFFLINE_ACTION_LAST, "PK_OFFLINE_ACTION_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkOfflineAction"), values);
    }
    return etype;
}

GType pk_offline_error_get_type (void) G_GNUC_CONST;

GType
pk_offline_error_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_OFFLINE_ERROR_FAILED, "PK_OFFLINE_ERROR_FAILED", "failed" },
            { PK_OFFLINE_ERROR_INVALID_VALUE, "PK_OFFLINE_ERROR_INVALID_VALUE", "invalid-value" },
            { PK_OFFLINE_ERROR_NO_DATA, "PK_OFFLINE_ERROR_NO_DATA", "no-data" },
            { PK_OFFLINE_ERROR_LAST, "PK_OFFLINE_ERROR_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkOfflineError"), values);
    }
    return etype;
}

#include "pk-package-sack.h"
/* enumerations from "pk-package-sack.h" */
GType pk_package_sack_sort_type_get_type (void) G_GNUC_CONST;

GType
pk_package_sack_sort_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_PACKAGE_SACK_SORT_TYPE_NAME, "PK_PACKAGE_SACK_SORT_TYPE_NAME", "name" },
            { PK_PACKAGE_SACK_SORT_TYPE_INFO, "PK_PACKAGE_SACK_SORT_TYPE_INFO", "info" },
            { PK_PACKAGE_SACK_SORT_TYPE_PACKAGE_ID, "PK_PACKAGE_SACK_SORT_TYPE_PACKAGE_ID", "package-id" },
            { PK_PACKAGE_SACK_SORT_TYPE_SUMMARY, "PK_PACKAGE_SACK_SORT_TYPE_SUMMARY", "summary" },
            { PK_PACKAGE_SACK_SORT_TYPE_LAST, "PK_PACKAGE_SACK_SORT_TYPE_LAST", "last" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkPackageSackSortType"), values);
    }
    return etype;
}

#include "pk-progress.h"
/* enumerations from "pk-progress.h" */
GType pk_progress_type_get_type (void) G_GNUC_CONST;

GType
pk_progress_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { PK_PROGRESS_TYPE_PACKAGE_ID, "PK_PROGRESS_TYPE_PACKAGE_ID", "package-id" },
            { PK_PROGRESS_TYPE_TRANSACTION_ID, "PK_PROGRESS_TYPE_TRANSACTION_ID", "transaction-id" },
            { PK_PROGRESS_TYPE_PERCENTAGE, "PK_PROGRESS_TYPE_PERCENTAGE", "percentage" },
            { PK_PROGRESS_TYPE_ALLOW_CANCEL, "PK_PROGRESS_TYPE_ALLOW_CANCEL", "allow-cancel" },
            { PK_PROGRESS_TYPE_STATUS, "PK_PROGRESS_TYPE_STATUS", "status" },
            { PK_PROGRESS_TYPE_ROLE, "PK_PROGRESS_TYPE_ROLE", "role" },
            { PK_PROGRESS_TYPE_CALLER_ACTIVE, "PK_PROGRESS_TYPE_CALLER_ACTIVE", "caller-active" },
            { PK_PROGRESS_TYPE_ELAPSED_TIME, "PK_PROGRESS_TYPE_ELAPSED_TIME", "elapsed-time" },
            { PK_PROGRESS_TYPE_REMAINING_TIME, "PK_PROGRESS_TYPE_REMAINING_TIME", "remaining-time" },
            { PK_PROGRESS_TYPE_SPEED, "PK_PROGRESS_TYPE_SPEED", "speed" },
            { PK_PROGRESS_TYPE_DOWNLOAD_SIZE_REMAINING, "PK_PROGRESS_TYPE_DOWNLOAD_SIZE_REMAINING", "download-size-remaining" },
            { PK_PROGRESS_TYPE_UID, "PK_PROGRESS_TYPE_UID", "uid" },
            { PK_PROGRESS_TYPE_PACKAGE, "PK_PROGRESS_TYPE_PACKAGE", "package" },
            { PK_PROGRESS_TYPE_ITEM_PROGRESS, "PK_PROGRESS_TYPE_ITEM_PROGRESS", "item-progress" },
            { PK_PROGRESS_TYPE_TRANSACTION_FLAGS, "PK_PROGRESS_TYPE_TRANSACTION_FLAGS", "transaction-flags" },
            { PK_PROGRESS_TYPE_INVALID, "PK_PROGRESS_TYPE_INVALID", "invalid" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("PkProgressType"), values);
    }
    return etype;
}

 /**/

/* Generated data ends here */

