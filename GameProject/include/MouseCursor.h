#ifndef __MOUSECURSOR_H__
#define __MOUSECURSOR_H__
 
#include <OgrePanelOverlayElement.h>
 
using namespace Ogre;
 
class MouseCursor
{
public:
    MouseCursor(): mGuiOverlay(0), mCursorContainer(0)
    {
        mMaterial = MaterialManager::getSingleton().create("MouseCursor/default", "General");
        mCursorContainer = (OverlayContainer*) OverlayManager::getSingletonPtr()->createOverlayElement("Panel", "MouseCursor");
        mCursorContainer->setMaterialName(mMaterial->getName());
        mCursorContainer->setPosition(0, 0);
 
        mGuiOverlay = OverlayManager::getSingletonPtr()->create("MouseCursor");
        mGuiOverlay->setZOrder(649);
        mGuiOverlay->add2D(mCursorContainer);
        mGuiOverlay->show();
    }
    ~MouseCursor() {}
 
    void setImage(const String& filename)
    {
        mTexture = TextureManager::getSingleton().load(filename, "General");
        TextureUnitState *pTexState;

        if(mMaterial->getTechnique(0)->getPass(0)->getNumTextureUnitStates())
            pTexState = mMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0);
        else
            pTexState = mMaterial->getTechnique(0)->getPass(0)->createTextureUnitState( mTexture->getName() );

        pTexState->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
        mMaterial->getTechnique(0)->getPass(0)->setSceneBlending(SBT_TRANSPARENT_ALPHA);
    }
 
    void setWindowDimensions(unsigned int width, unsigned int height) 
    {
        mWindowWidth = (width > 0) ? width : 1;
        mWindowHeight = (height > 0) ? height : 1;
 
        mCursorContainer->setWidth(mTexture->getWidth() / mWindowWidth);
        mCursorContainer->setHeight(mTexture->getHeight() / mWindowHeight);
    }
 
    void setVisible(bool visible) { visible ? mCursorContainer->show() : mCursorContainer->hide(); }
 
    void updatePosition(int x, int y)
    {
        Real rx = x / mWindowWidth;
        Real ry = y / mWindowHeight;
        mCursorContainer->setPosition(std::min<Real>(rx, 1.0f), std::min<Real>(ry, 1.0f));
    }

private:
    Overlay* mGuiOverlay;
    OverlayContainer* mCursorContainer;
    TexturePtr mTexture;
    MaterialPtr mMaterial;
 
    Real mWindowWidth;
    Real mWindowHeight;
};
 
#endif