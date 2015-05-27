#include "packettransportmock.h"

PacketTransportMock::PacketTransportMock() : PacketTransport()
{
}

void PacketTransportMock::makeConnection(QString address, quint16 port)
{
    Q_UNUSED(address)
    Q_UNUSED(port)
}

void PacketTransportMock::sendPacket(Packet packet)
{
    sentPacket = packet;
}

Packet PacketTransportMock::getSentPacket()
{
    return sentPacket;
}
