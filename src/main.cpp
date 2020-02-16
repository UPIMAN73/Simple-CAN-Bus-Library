#include "canpacket.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    CANPacket tp; // Test Packet
    PacketHandler ph = PacketHandler();

    char message[8] = "";
    printf("Enter Message (8 Characters): ");
    cin >> message;

    tp.ID = 1;
    tp.r0 = 0;
    tp.DLC = 8;
    
    for (int i = 0; i < 8; i++)
    {
        tp.data[i] = (uchar) message[i];
    }

    tp.CRC = ph.CRC(tp);
    tp.ACKS = 0;

    ph.read(tp);

    return 0;
}