#include "TextField.h"

using namespace Ogre;

template<> TextField* Singleton<TextField>::msSingleton = 0;

TextField::TextField()
{
    mTimeToGo = 0.0;
    mJustAdded = false;
}

void TextField::init()
{
    mOverlay = OverlayManager::getSingleton().create("ScrollingOverlay");

    mPanel = static_cast<OverlayContainer*>(OverlayManager::getSingleton().createOverlayElement("Panel", "container1"));
    mPanel->setMetricsMode(GMM_PIXELS);
    mPanel->setDimensions(800, 400);
    mPanel->setPosition(5, 30);
 
    // now create the text...
    Ogre::String name;
    for (int i = 0; i < 3; ++i) 
    {
        name = "TextField"+StringConverter::toString(i);
        mTextBox[i] = OverlayManager::getSingleton().createOverlayElement("TextArea", name);
        mTextBox[i]->setMetricsMode(Ogre::GMM_PIXELS);
        mTextBox[i]->setDimensions(20, 5);        
        mTextBox[i]->setWidth(20);
        mTextBox[i]->setHeight(5);
 
        mTextBox[i]->setPosition(POSITION_TOP_X, POSITION_TOP_Y+i*SPACING);
        mTextBox[i]->setParameter("font_name", "StarWars");
        mTextBox[i]->setParameter("char_height", "16");
        mTextBox[i]->setColour(ColourValue::White);
        mTextBox[i]->setCaption(" ");
        mPanel->addChild(mTextBox[i]);
    }

    mOverlay->add2D(mPanel);
    mOverlay->show();
}

void TextField::addText(Ogre::String const& text)
{
    // first swap the content...
    mTextBox[2]->setCaption(mTextBox[1]->getCaption());
    mTextBox[1]->setCaption(mTextBox[0]->getCaption());
    mTextBox[0]->setCaption(text);
    // but hide the first textbox first...
    mTextBox[0]->hide();
    // and move the others to upper coordinate...
    mTextBox[1]->setPosition(POSITION_TOP_X, POSITION_TOP_Y);
    mTextBox[2]->setPosition(POSITION_TOP_X, POSITION_TOP_Y+SPACING);
    mTimeToGo = 1.5; // 1.5 seconds...
    mJustAdded = true;
}

void TextField::repeat(Ogre::Real time)
{
    if (mJustAdded) 
    {
        mTimeToGo -= time;

        if (mTimeToGo <= 1.0)
            mTextBox[0]->show();

        if (mTimeToGo < 1e-3) 
        {
            mTimeToGo = 0.0;
            mJustAdded = false;
        }

        // scroll the textbox by this much..
        Real progress = (1.5-mTimeToGo)/1.5;
        Real y = POSITION_TOP_Y+SPACING*progress;
        mTextBox[1]->setPosition(POSITION_TOP_X, y);
        mTextBox[1]->setColour(ColourValue(1,1,1,1.0-progress/4));
        mTextBox[2]->setPosition(POSITION_TOP_X, y+SPACING);
        mTextBox[2]->setColour(ColourValue(1,1,1,1.0-progress*progress));
    }
}