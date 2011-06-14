/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c TransactionProxy -p transactionproxy -m -N ../../src/org.freedesktop.PackageKit.Transaction.xml
 *
 * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef TRANSACTIONPROXY_H_1307434500
#define TRANSACTIONPROXY_H_1307434500

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.PackageKit.Transaction
 */
class TransactionProxy: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.PackageKit.Transaction"; }

public:
    TransactionProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~TransactionProxy();

    Q_PROPERTY(bool AllowCancel READ allowCancel)
    inline bool allowCancel() const
    { return qvariant_cast< bool >(property("AllowCancel")); }

    Q_PROPERTY(bool CallerActive READ callerActive)
    inline bool callerActive() const
    { return qvariant_cast< bool >(property("CallerActive")); }

    Q_PROPERTY(uint ElapsedTime READ elapsedTime)
    inline uint elapsedTime() const
    { return qvariant_cast< uint >(property("ElapsedTime")); }

    Q_PROPERTY(QString LastPackage READ lastPackage)
    inline QString lastPackage() const
    { return qvariant_cast< QString >(property("LastPackage")); }

    Q_PROPERTY(uint Percentage READ percentage)
    inline uint percentage() const
    { return qvariant_cast< uint >(property("Percentage")); }

    Q_PROPERTY(uint RemainingTime READ remainingTime)
    inline uint remainingTime() const
    { return qvariant_cast< uint >(property("RemainingTime")); }

    Q_PROPERTY(QString Role READ role)
    inline QString role() const
    { return qvariant_cast< QString >(property("Role")); }

    Q_PROPERTY(uint Speed READ speed)
    inline uint speed() const
    { return qvariant_cast< uint >(property("Speed")); }

    Q_PROPERTY(QString Status READ status)
    inline QString status() const
    { return qvariant_cast< QString >(property("Status")); }

    Q_PROPERTY(uint Subpercentage READ subpercentage)
    inline uint subpercentage() const
    { return qvariant_cast< uint >(property("Subpercentage")); }

    Q_PROPERTY(uint Uid READ uid)
    inline uint uid() const
    { return qvariant_cast< uint >(property("Uid")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> AcceptEula(const QString &eula_id)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(eula_id);
        return asyncCallWithArgumentList(QLatin1String("AcceptEula"), argumentList);
    }

    inline QDBusPendingReply<> Cancel()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Cancel"), argumentList);
    }

    inline QDBusPendingReply<> DownloadPackages(bool store_in_cache, const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(store_in_cache) << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("DownloadPackages"), argumentList);
    }

    inline QDBusPendingReply<> GetCategories()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetCategories"), argumentList);
    }

    inline QDBusPendingReply<> GetDepends(const QString &filter, const QStringList &package_ids, bool recursive)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(package_ids) << qVariantFromValue(recursive);
        return asyncCallWithArgumentList(QLatin1String("GetDepends"), argumentList);
    }

    inline QDBusPendingReply<> GetDetails(const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("GetDetails"), argumentList);
    }

    inline QDBusPendingReply<> GetDistroUpgrades()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetDistroUpgrades"), argumentList);
    }

    inline QDBusPendingReply<> GetFiles(const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("GetFiles"), argumentList);
    }

    inline QDBusPendingReply<> GetOldTransactions(uint number)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(number);
        return asyncCallWithArgumentList(QLatin1String("GetOldTransactions"), argumentList);
    }

    inline QDBusPendingReply<> GetPackages(const QString &filter)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter);
        return asyncCallWithArgumentList(QLatin1String("GetPackages"), argumentList);
    }

    inline QDBusPendingReply<> GetRepoList(const QString &filter)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter);
        return asyncCallWithArgumentList(QLatin1String("GetRepoList"), argumentList);
    }

    inline QDBusPendingReply<> GetRequires(const QString &filter, const QStringList &package_ids, bool recursive)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(package_ids) << qVariantFromValue(recursive);
        return asyncCallWithArgumentList(QLatin1String("GetRequires"), argumentList);
    }

    inline QDBusPendingReply<> GetUpdateDetail(const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("GetUpdateDetail"), argumentList);
    }

    inline QDBusPendingReply<> GetUpdates(const QString &filter)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter);
        return asyncCallWithArgumentList(QLatin1String("GetUpdates"), argumentList);
    }

    inline QDBusPendingReply<> InstallFiles(bool only_trusted, const QStringList &full_paths)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(only_trusted) << qVariantFromValue(full_paths);
        return asyncCallWithArgumentList(QLatin1String("InstallFiles"), argumentList);
    }

    inline QDBusPendingReply<> InstallPackages(bool only_trusted, const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(only_trusted) << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("InstallPackages"), argumentList);
    }

    inline QDBusPendingReply<> InstallSignature(const QString &sig_type, const QString &key_id, const QString &package_id)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(sig_type) << qVariantFromValue(key_id) << qVariantFromValue(package_id);
        return asyncCallWithArgumentList(QLatin1String("InstallSignature"), argumentList);
    }

    inline QDBusPendingReply<> RefreshCache(bool force)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(force);
        return asyncCallWithArgumentList(QLatin1String("RefreshCache"), argumentList);
    }

    inline QDBusPendingReply<> RemovePackages(const QStringList &package_ids, bool allow_deps, bool autoremove)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids) << qVariantFromValue(allow_deps) << qVariantFromValue(autoremove);
        return asyncCallWithArgumentList(QLatin1String("RemovePackages"), argumentList);
    }

    inline QDBusPendingReply<> RepoEnable(const QString &repo_id, bool enabled)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(repo_id) << qVariantFromValue(enabled);
        return asyncCallWithArgumentList(QLatin1String("RepoEnable"), argumentList);
    }

    inline QDBusPendingReply<> RepoSetData(const QString &repo_id, const QString &parameter, const QString &value)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(repo_id) << qVariantFromValue(parameter) << qVariantFromValue(value);
        return asyncCallWithArgumentList(QLatin1String("RepoSetData"), argumentList);
    }

    inline QDBusPendingReply<> Resolve(const QString &filter, const QStringList &packages)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(packages);
        return asyncCallWithArgumentList(QLatin1String("Resolve"), argumentList);
    }

    inline QDBusPendingReply<> Rollback(const QString &transaction_id)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(transaction_id);
        return asyncCallWithArgumentList(QLatin1String("Rollback"), argumentList);
    }

    inline QDBusPendingReply<> SearchDetails(const QString &filter, const QStringList &values)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(values);
        return asyncCallWithArgumentList(QLatin1String("SearchDetails"), argumentList);
    }

    inline QDBusPendingReply<> SearchFiles(const QString &filter, const QStringList &values)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(values);
        return asyncCallWithArgumentList(QLatin1String("SearchFiles"), argumentList);
    }

    inline QDBusPendingReply<> SearchGroups(const QString &filter, const QStringList &values)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(values);
        return asyncCallWithArgumentList(QLatin1String("SearchGroups"), argumentList);
    }

    inline QDBusPendingReply<> SearchNames(const QString &filter, const QStringList &values)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(values);
        return asyncCallWithArgumentList(QLatin1String("SearchNames"), argumentList);
    }

    inline QDBusPendingReply<> SetHints(const QStringList &hints)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(hints);
        return asyncCallWithArgumentList(QLatin1String("SetHints"), argumentList);
    }

    inline QDBusPendingReply<> SimulateInstallFiles(const QStringList &full_paths)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(full_paths);
        return asyncCallWithArgumentList(QLatin1String("SimulateInstallFiles"), argumentList);
    }

    inline QDBusPendingReply<> SimulateInstallPackages(const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("SimulateInstallPackages"), argumentList);
    }

    inline QDBusPendingReply<> SimulateRemovePackages(const QStringList &package_ids, bool autoremove)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids) << qVariantFromValue(autoremove);
        return asyncCallWithArgumentList(QLatin1String("SimulateRemovePackages"), argumentList);
    }

    inline QDBusPendingReply<> SimulateUpdatePackages(const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("SimulateUpdatePackages"), argumentList);
    }

    inline QDBusPendingReply<> UpdatePackages(bool only_trusted, const QStringList &package_ids)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(only_trusted) << qVariantFromValue(package_ids);
        return asyncCallWithArgumentList(QLatin1String("UpdatePackages"), argumentList);
    }

    inline QDBusPendingReply<> UpdateSystem(bool only_trusted)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(only_trusted);
        return asyncCallWithArgumentList(QLatin1String("UpdateSystem"), argumentList);
    }

    inline QDBusPendingReply<> UpgradeSystem(const QString &distro_id, const QString &upgrade_kind)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(distro_id) << qVariantFromValue(upgrade_kind);
        return asyncCallWithArgumentList(QLatin1String("UpgradeSystem"), argumentList);
    }

    inline QDBusPendingReply<> WhatProvides(const QString &filter, const QString &type, const QStringList &values)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(filter) << qVariantFromValue(type) << qVariantFromValue(values);
        return asyncCallWithArgumentList(QLatin1String("WhatProvides"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Category(const QString &parent_id, const QString &cat_id, const QString &name, const QString &summary, const QString &icon);
    void Changed();
    void Destroy();
    void Details(const QString &package_id, const QString &license, const QString &group, const QString &detail, const QString &url, qulonglong size);
    void DistroUpgrade(const QString &type, const QString &name, const QString &summary);
    void ErrorCode(const QString &code, const QString &details);
    void EulaRequired(const QString &eula_id, const QString &package_id, const QString &vendor_name, const QString &license_agreement);
    void Files(const QString &package_id, const QString &file_list);
    void Finished(const QString &exit, uint runtime);
    void MediaChangeRequired(const QString &media_type, const QString &media_id, const QString &media_text);
    void Message(const QString &type, const QString &details);
    void Package(const QString &info, const QString &package_id, const QString &summary);
    void RepoDetail(const QString &repo_id, const QString &description, bool enabled);
    void RepoSignatureRequired(const QString &package_id, const QString &repository_name, const QString &key_url, const QString &key_userid, const QString &key_id, const QString &key_fingerprint, const QString &key_timestamp, const QString &type);
    void RequireRestart(const QString &type, const QString &package_id);
    void Transaction(const QString &old_tid, const QString &timespec, bool succeeded, const QString &role, uint duration, const QString &data, uint uid, const QString &cmdline);
    void UpdateDetail(const QString &package_id, const QString &updates, const QString &obsoletes, const QString &vendor_url, const QString &bugzilla_url, const QString &cve_url, const QString &restart, const QString &update_text, const QString &changelog, const QString &state, const QString &issued, const QString &updated);
};

#endif
