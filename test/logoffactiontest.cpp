#include <QTest>

#include "logoffactiontest.h"
#include "asteriskmanager.h"
#include "packettransport.h"
#include "packettransportmock.h"
#include "logoffaction.h"

LogoffActionTest::LogoffActionTest(QObject *parent) : QObject(parent)
{
}

void LogoffActionTest::testLogoffMessageSent()
{
    AsteriskManager *asteriskManager = new AsteriskManager;
    PacketTransportMock *packetTransport = new PacketTransportMock;
    LogoffAction *logoffAction = new LogoffAction;

    asteriskManager->setPacketTransport(packetTransport);
    asteriskManager->sendAction(logoffAction);

    Packet sentPacket = packetTransport->getSentPacket();

    QCOMPARE(sentPacket.field("Action").toString(), QString("Logoff"));
}
