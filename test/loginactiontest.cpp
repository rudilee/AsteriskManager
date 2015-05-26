#include <QTest>

#include "loginactiontest.h"
#include "asteriskmanager.h"
#include "packettransport.h"
#include "packettransportmock.h"
#include "loginaction.h"

LoginActionTest::LoginActionTest(QObject *parent) : QObject(parent)
{
}

void LoginActionTest::testLoginMessageSent()
{
    AsteriskManager *asteriskManager = new AsteriskManager;
    PacketTransportMock *packetTransport = new PacketTransportMock;
    LoginAction *loginAction = new LoginAction;

    asteriskManager->setPacketTransport(packetTransport);
    loginAction->setUsername("test");
    loginAction->setSecret("pass123");
    asteriskManager->sendAction(loginAction);

    Packet sentPacket = packetTransport->getSentPacket();

    QCOMPARE(sentPacket.field("Action").toString(), QString("Login"));
    QCOMPARE(sentPacket.field("Username").toString(), QString("test"));
    QCOMPARE(sentPacket.field("Secret").toString(), QString("pass123"));
}
