#ifndef PACKETTRANSPORTMOCK_H
#define PACKETTRANSPORTMOCK_H

#include "packettransport.h"
#include "packet.h"

class PacketTransportMock : public PacketTransport
{
public:
    explicit PacketTransportMock();

    void makeConnection(QString address, quint16 port);
    void sendPacket(Packet packet);
    Packet getSentPacket();

private:
    Packet sentPacket;
};

#endif // PACKETTRANSPORTMOCK_H
