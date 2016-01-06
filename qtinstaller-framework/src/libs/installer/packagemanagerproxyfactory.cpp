/**************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Installer Framework.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
**
** $QT_END_LICENSE$
**
**************************************************************************/

#include "packagemanagerproxyfactory.h"

#include "packagemanagercore.h"
#include "settings.h"

#include <QNetworkProxy>

namespace QInstaller {

PackageManagerProxyFactory::PackageManagerProxyFactory(const PackageManagerCore *const core)
    : m_core(core)
{
}

PackageManagerProxyFactory *PackageManagerProxyFactory::clone() const
{
    PackageManagerProxyFactory *factory = new PackageManagerProxyFactory(m_core);
    factory->m_proxyCredentials = m_proxyCredentials;
    return factory;
}

struct FindProxyCredential {
    FindProxyCredential(const QString &host, int port) : host(host), port(port) {}

    bool operator()(const ProxyCredential &c) { return c.host == host && c.port == port; }
private:
    QString host;
    int port;
};

QList<QNetworkProxy> PackageManagerProxyFactory::queryProxy(const QNetworkProxyQuery &query)
{
    const Settings &settings = m_core->settings();
    QList<QNetworkProxy> list;

    if (settings.proxyType() == Settings::SystemProxy) {
#if defined(Q_OS_UNIX) && !defined(Q_OS_OSX)
        QUrl proxyUrl = QUrl::fromUserInput(QString::fromUtf8(qgetenv("http_proxy")));
        if (proxyUrl.isValid()) {
            return list << QNetworkProxy(QNetworkProxy::HttpProxy, proxyUrl.host(), proxyUrl.port(),
                proxyUrl.userName(), proxyUrl.password());
        }
#endif
        QList<QNetworkProxy> systemProxies = systemProxyForQuery(query);

        auto proxyIter = systemProxies.begin();
        for (; proxyIter != systemProxies.end(); ++proxyIter) {
            QNetworkProxy &proxy = *proxyIter;
            auto p = std::find_if(m_proxyCredentials.constBegin(), m_proxyCredentials.constEnd(),
                                  FindProxyCredential(proxy.hostName(), proxy.port()));
            if (p != m_proxyCredentials.constEnd()) {
                proxy.setUser(p->user);
                proxy.setPassword(p->password);
            }
        }
        return systemProxies;
    }

    if ((settings.proxyType() == Settings::NoProxy))
        return list << QNetworkProxy(QNetworkProxy::NoProxy);

    if (query.queryType() == QNetworkProxyQuery::UrlRequest) {
        QNetworkProxy proxy;
        if (query.url().scheme() == QLatin1String("ftp")) {
            proxy = settings.ftpProxy();
        } else if (query.url().scheme() == QLatin1String("http")
                 || query.url().scheme() == QLatin1String("https")) {
            proxy = settings.httpProxy();
        }


        auto p = std::find_if(m_proxyCredentials.constBegin(), m_proxyCredentials.constEnd(),
                              FindProxyCredential(proxy.hostName(), proxy.port()));
        if (p != m_proxyCredentials.constEnd()) {
            proxy.setUser(p->user);
            proxy.setPassword(p->password);
        }
        return list << proxy;
    }
    return list << QNetworkProxy(QNetworkProxy::DefaultProxy);
}

void PackageManagerProxyFactory::setProxyCredentials(const QNetworkProxy &proxy,
                                                     const QString &user,
                                                     const QString &password)
{
    auto p = std::find_if(m_proxyCredentials.begin(), m_proxyCredentials.end(),
                          FindProxyCredential(proxy.hostName(), proxy.port()));

    if (p == m_proxyCredentials.end()) {
        ProxyCredential proxyCredential;
        proxyCredential.host = proxy.hostName();
        proxyCredential.port = proxy.port();
        proxyCredential.user = user;
        proxyCredential.password = password;
        m_proxyCredentials.append(proxyCredential);
    } else {
        p->user = user;
        p->password = password;
    }
}

}   // QInstaller