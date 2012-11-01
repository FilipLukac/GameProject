#include <iostream>
#include "GameProjectServer.h"

using namespace std;

int main(int argc, char **arv)
{
    GameProjectServer *server = new GameProjectServer();
    cout << "Loading player data...\n";
    server->LoadPlayerData();



    delete server;
    cin.get();
    return 0;
}