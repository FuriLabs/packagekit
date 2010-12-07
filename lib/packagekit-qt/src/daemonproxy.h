/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -c DaemonProxy -p daemonproxy -m -N ../../../src/org.freedesktop.PackageKit.xml
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DAEMONPROXY_H_1283279739
#define DAEMONPROXY_H_1283279739

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.PackageKit
 */
class DaemonProxy: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.PackageKit"; }

public:
    DaemonProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~DaemonProxy();

    Q_PROPERTY(QString BackendAuthor READ backendAuthor)
    inline QString backendAuthor() const
    { return qvariant_cast< QString >(property("BackendAuthor")); }

    Q_PROPERTY(QString BackendDescription READ backendDescription)
    inline QString backendDescription() const
    { return qvariant_cast< QString >(property("BackendDescription")); }

    Q_PROPERTY(QString BackendName READ backendName)
    inline QString backendName() const
    { return qvariant_cast< QString >(property("BackendName")); }

    Q_PROPERTY(QString DistroId READ distroId)
    inline QString distroId() const
    { return qvariant_cast< QString >(property("DistroId")); }

    Q_PROPERTY(QString Filters READ filters)
    inline QString filters() const
    { return qvariant_cast< QString >(property("Filters")); }

    Q_PROPERTY(QString Groups READ groups)
    inline QString groups() const
    { return qvariant_cast< QString >(property("Groups")); }

    Q_PROPERTY(bool Locked READ locked)
    inline bool locked() const
    { return qvariant_cast< bool >(property("Locked")); }

    Q_PROPERTY(QString MimeTypes READ mimeTypes)
    inline QString mimeTypes() const
    { return qvariant_cast< QString >(property("MimeTypes")); }

    Q_PROPERTY(QString NetworkState READ networkState)
    inline QString networkState() const
    { return qvariant_cast< QString >(property("NetworkState")); }

    Q_PROPERTY(QString Roles READ roles)
    inline QString roles() const
    { return qvariant_cast< QString >(property("Roles")); }

    Q_PROPERTY(uint VersionMajor READ versionMajor)
    inline uint versionMajor() const
    { return qvariant_cast< uint >(property("VersionMajor")); }

    Q_PROPERTY(uint VersionMicro READ versionMicro)
    inline uint versionMicro() const
    { return qvariant_cast< uint >(property("VersionMicro")); }

    Q_PROPERTY(uint VersionMinor READ versionMinor)
    inline uint versionMinor() const
    { return qvariant_cast< uint >(property("VersionMinor")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString> CanAuthorize(const QString &action_id)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(action_id);
        return asyncCallWithArgumentList(QLatin1String("CanAuthorize"), argumentList);
    }

    inline QDBusPendingReply<QString> GetDaemonState()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetDaemonState"), argumentList);
    }

    inline QDBusPendingReply<QString> GetTid()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetTid"), argumentList);
    }

    inline QDBusPendingReply<uint> GetTimeSinceAction(const QString &role)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(role);
        return asyncCallWithArgumentList(QLatin1String("GetTimeSinceAction"), argumentList);
    }

    inline QDBusPendingReply<QStringList> GetTransactionList()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetTransactionList"), argumentList);
    }

    inline QDBusPendingReply<> SetProxy(const QString &proxy_http, const QString &proxy_ftp)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(proxy_http) << qVariantFromValue(proxy_ftp);
        return asyncCallWithArgumentList(QLatin1String("SetProxy"), argumentList);
    }

    inline QDBusPendingReply<> SetRoot(const QString &root)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(root);
        return asyncCallWithArgumentList(QLatin1String("SetRoot"), argumentList);
    }

    inline QDBusPendingReply<> StateHasChanged(const QString &reason)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(reason);
        return asyncCallWithArgumentList(QLatin1String("StateHasChanged"), argumentList);
    }

    inline QDBusPendingReply<> SuggestDaemonQuit()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("SuggestDaemonQuit"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Changed();
    void RepoListChanged();
    void RestartSchedule();
    void TransactionListChanged(const QStringList &transactions);
    void UpdatesChanged();
};

#endif
