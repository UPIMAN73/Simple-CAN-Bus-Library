#include "canpacket.h"
#include <stdlib.h>
#include <string>

using namespace std;

PacketHandler::PacketHandler()
{
    if (m_opened)
    {
        // Close
    }

    else
    {
        m_opened = true;   
    }
}


// Read packet

void PacketHandler::read(CANPacket p)
{
    // convert CAN Packet Data to string
    string s = ""; 
    for (int i = 0; i < 8; i++)
    {
        s += to_string(p.data[i]) + " ";
    }

    // print out the string
    printf("\nID: %d\nR0: %d\nData Length: %d\nData: %s\nCRC: %d\n", p.ID, p.r0, p.DLC, s.c_str(), p.CRC);
}

void PacketHandler::write(CANPacket p)
{
    // write to the CANBUS
}

// CRC Calculations
ushort PacketHandler::CRC(CANPacket cp)
{
    ushort crc = 0xFFFF; // Start CRC Bit
    crc ^= cp.ID;
    crc ^= cp.DLC;

    // CRC Calculation Across Data
    for (int i = 0; i < 8; i++)
    {
        crc ^= cp.data[i];
    }

    return crc;
}