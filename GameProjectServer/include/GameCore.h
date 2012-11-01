#ifndef __GAMEPROJECT_SERVER__
#define __GAMEPROJECT_SERVER__

class GameProjectServer
{
public:

    void HandleChangedHp(/*Packet *data*/);
    void HandleChangedMana(/*Packet *data*/);
    void HandleChangePosition(/*Packet *data*/);


    void HandleLoginInWorld(/*Packet *data*/);
    void HandleLogoutWorld/*Packet *data*/();
    void HandleUsernameAndPassword(/*Packet *data*/);


    GameProjectServer();
    virtual ~GameProjectServer();
}


#endif