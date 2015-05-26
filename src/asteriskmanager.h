#ifndef ASTERISKMANAGER_H
#define ASTERISKMANAGER_H

#include <QObject>
#include <QHash>

#include "packettransport.h"
#include "action.h"

class AsteriskManager : public QObject
{
    Q_OBJECT

public:
    explicit AsteriskManager(QObject *parent = 0);

    void setPacketTransport(PacketTransport *packetTransport);
    void sendAction(Action *action);

    void login(QString username, QString secret);
    void logout();

private:
    bool loggedIn;
    PacketTransport *packetTransport;
    QHash<QString, Action *> activeActions;

private slots:
    void dispatchPacket(Packet packet);

signals:
    void eventReceived(Packet event);
};

#endif // ASTERISKMANAGER_H
