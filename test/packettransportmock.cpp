#include "packettransportmock.h"

PacketTransportMock::PacketTransportMock() : PacketTransport()
{
}

void PacketTransportMock::sendPacket(Packet packet)
{
    sentPacket = packet;
}

Packet PacketTransportMock::getSentPacket()
{
    return sentPacket;
}
