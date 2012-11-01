#include "GameProjectServer.h"


GameProjectServer::GameProjectServer()
{
}


void GameProjectServer::LoadPlayerData()
{
    // Just test it, our data will be handle in MySQL database
    PlayerData data;
    data.health = 1;
    data.mana = 1;
    data.pos.x = 1.0f;
    data.pos.y = 1.0f;
    data.pos.z = 1.0f;

    m_playerMap[1] = "Test";
}