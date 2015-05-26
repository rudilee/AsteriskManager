#include "asteriskmanager.h"
#include "loginaction.h"
#include "logoffaction.h"

AsteriskManager::AsteriskManager(QObject *parent) : QObject(parent),
    loggedIn(false)
{
}

void AsteriskManager::setPacketTransport(PacketTransport *packetTransport)
{
    this->packetTransport = packetTransport;
}

void AsteriskManager::sendAction(Action *action)
{
    packetTransport->sendPacket(*action);

    activeActions.insert(action->getActionId(), action);
}

void AsteriskManager::login(QString username, QString secret)
{
    LoginAction *login = new LoginAction;
    login->setUsername(username);
    login->setSecret(secret);

    connect(login, &Action::responseReceived, [=] (Packet response) {
        loggedIn = (response.field("Response").toString() == "Success");

        login->deleteLater();
    });

    sendAction(login);
}

void AsteriskManager::logout()
{
    LogoffAction *logoff = new LogoffAction;

    connect(logoff, &Action::responseReceived, [=] (Packet response) {
        loggedIn = false;

        logoff->deleteLater();

        Q_UNUSED(response)
    });

    sendAction(logoff);
}

void AsteriskManager::dispatchPacket(Packet packet)
{
    switch (packet.type()) {
    case Packet::Response: {
        QString actionId = packet.field("ActionID").toString();

        if (activeActions.contains(actionId)) {
            activeActions.value(actionId)->responseReceived(packet);
            activeActions.remove(actionId);
        }

        break;
    }
    case Packet::Event: emit eventReceived(packet);
        break;
    }
}
