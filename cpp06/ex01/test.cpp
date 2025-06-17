#include <iostream>
#include <cstdint>
#include <cstring>

#pragma pack(push, 1)
struct Packet {
    uint32_t id;
    float positionX;
    float positionY;
};
#pragma pack(pop)

int main()
{
    uint8_t buffer[12] = {
        0x01, 0x00, 0x00, 0x00,       // id = 1
        0x00, 0x00, 0x80, 0x3F,       // positionX = 1.0f (IEEE-754)
        0xCD, 0xCC, 0x4C, 0x3F        // positionY = 0.8f (IEEE-754)
    };

    Packet* packet = reinterpret_cast<Packet*>(buffer);

    std::cout << "[Raw Packet Interpreted via reinterpret_cast]\n";
    std::cout << "ID        : " << packet->id << "\n";
    std::cout << "PositionX : " << packet->positionX << "\n";
    std::cout << "PositionY : " << packet->positionY << "\n";

    return 0;
}