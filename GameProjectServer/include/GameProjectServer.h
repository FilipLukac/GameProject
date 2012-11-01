#ifndef __GAMEPROJECT_SERVER__
#define __GAMEPROJECT_SERVER__

#include "Global.h"
#include <iostream>

enum serverOpcodes
{
    CMSG_OPCODE_LOGIN                 = 0x1,
    CMSG_OPCODE_LOGOUT                = 0x2,

    SMSG_OPCODE_CHANGE_POSITION       = 0x4,
    SMSG_OPCODE_CHANGE_HP             = 0x8,
    SMSG_OPCODE_CHANGE_MANA           = 0x16,

};

struct PlayerPosition
{
    float x;
    float y;
    float z;
};

struct PlayerData
{
    int id;

    uint32 health;
    uint32 mana;

    char *name;

    PlayerPosition pos;
};

class GameProjectServer
{
public:


    void LoadPlayerData();

    void HandleChangedHp(/*Packet *data*/);
    void HandleChangedMana(/*Packet *data*/);
    void HandleChangePosition(/*Packet *data*/);

    void HandleLoginInWorld(/*Packet *data*/);
    void HandleLogoutWorld(/*Packet *data*/);
    void HandleUsernameAndPassword(/*Packet *data*/);


    GameProjectServer();
    virtual ~GameProjectServer();
};


#endif