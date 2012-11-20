#ifndef __TEXT_FIELD__
#define __TEXT_FIELD__
#include "GameCore.h"
#include "BaseApplication.h"


#pragma once


class TextField : public Ogre::Singleton<TextField>
{
public:
    TextField();
    void init();
    void addText(Ogre::String const& text);
    void repeat(Ogre::Real time);

protected:
    enum
    {
        POSITION_TOP_X = 5,
        POSITION_TOP_Y = 30,
        SPACING = 30
    };

    Ogre::OverlayContainer* mPanel;
    Ogre::Overlay* mOverlay;
    Ogre::OverlayElement* mTextBox[3];
    Ogre::Real mTimeToGo;
    bool mJustAdded;

    bool justAdded;

};

#endif