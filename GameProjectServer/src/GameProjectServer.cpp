#include "GameProjectServer.h"
#include <ctime>

GameProjectServer::GameProjectServer()
{
}


void GameProjectServer::LoadPlayerData()
{
    uint32 oldTime = time(NULL);
    // Just test it, our data will be handle in MySQL database
    PlayerData data;
    data.health = 1;
    data.mana = 1;
    data.pos.x = 1.0f;
    data.pos.y = 1.0f;
    data.pos.z = 1.0f;


    m_playerMap[1] = "Test";
    std::cout << "Player data loaded in " << getMSTimeDiff(oldTime, time(NULL)) << "seconds" << std::endl;
}

uint32 GameProjectServer::getMSTimeDiff(uint32 oldMSTime, uint32 newMSTime)
{
    // getMSTime() have limited data range and this is case when it overflow in this tick
    if (oldMSTime > newMSTime)
        return (0xFFFFFFFF - oldMSTime) + newMSTime;
    else
        return newMSTime - oldMSTime;
}