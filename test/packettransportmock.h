#ifndef PACKETTRANSPORTMOCK_H
#define PACKETTRANSPORTMOCK_H

#include "packettransport.h"
#include "packet.h"

class PacketTransportMock : public PacketTransport
{
public:
    explicit PacketTransportMock();

    void sendPacket(Packet packet);
    Packet getSentPacket();

private:
    Packet sentPacket;
};

#endif // PACKETTRANSPORTMOCK_H
