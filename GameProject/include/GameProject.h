#ifndef __GameProject_h_
#define __GameProject_h_

#include "BaseApplication.h"
#include "GameCore.h"
#include "SdkSample.h"
#include "MouseCursor.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "../res/resource.h"
#endif

struct PlayerPosition
{
    Ogre::Real x;
    Ogre::Real y;
    Ogre::Real z;
};

struct PlayerData
{
    uint32 health;
    uint32 mana;
    PlayerPosition pos;
};

class GameProject : public BaseApplication
{
public:
    GameProject(void);
    virtual ~GameProject(void);

    // Helper functions for VALUE in std::map<string, string(value)>
    Ogre::NameValuePairList& getInfo() { return m_info; }
    void setInfoStr(Ogre::String str) { m_strInfo = str; }
    Ogre::String getStrInfo() const { return m_strInfo; }
    
    // Return pointer on GameCore
    GameCore* getGameCorePtr() { return core; }

private:
    Ogre::String getValueFromKey(Ogre::NameValuePairList& list, Ogre::String& key);
    MouseCursor *mMouseCursor;

protected:
    virtual void createScene(void);
    virtual void createGrassMesh(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    virtual bool keyPressed(const OIS::KeyEvent &arg );
    virtual bool keyReleased(const OIS::KeyEvent& evt);
    virtual bool mouseMoved(const OIS::MouseEvent& evt);
    virtual bool mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id);

    void insertHelpInfo(Ogre::String& str) { m_info["Help"] = str; }
    // custom variables

    GameCore *core;
    // Help dialog
    Ogre::NameValuePairList m_info;
    Ogre::String m_strInfo;
};

#endif // #ifndef __GameProject_h_
