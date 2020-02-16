#pragma once
#ifndef CANPACKET_H_
#define CANPACKET_H_


#include "generic.h"


/*
 * CAN Packet Structure
 */
struct CANPacket
{
    bool sof = SOF;
    ushort ID;              // ID (Identifier) (11 bits)
    bool RTR = 0;
    bool IDE = 0;
    bool r0;                // Reserved Bit r0 (0 dominant, 1 recessive)
    ushort DLC;             // DLC (Data length Code) number of bytes of data (0-8)
    uchar data[8] = {};     // DATA Frame  
    ushort CRC;             // CRC Checksum
    bool CRCD = 1;
    bool ACKS;              // ACK Slot (1 recessive, 0 dominant)
    bool ACKD = 1;
    uchar EOf = 0x0E;       // End of Frame (must be recessive) (7 bits)
};

// Packet Handler Class
class PacketHandler
{
    public:
        PacketHandler();

        // read
        void read(CANPacket p);

        // write
        void write(CANPacket cp);

        // CRC Calculation
        ushort CRC(CANPacket cp);
    
    private:
        bool m_opened = false;  // check the open status of the packet handler
        //static CANBUS cb;
};

#endif