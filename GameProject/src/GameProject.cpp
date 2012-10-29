#include "GameProject.h"
#include "SdkCameraMan.h"
#include "SdkSample.h"

using namespace Ogre;
using namespace OgreBites;


//-------------------------------------------------------------------------------------
GameProject::GameProject(void)
{
}
//-------------------------------------------------------------------------------------
GameProject::~GameProject(void)
{
}

bool GameProject::frameRenderingQueued(Ogre::FrameEvent const& evt)
{
    core->addTime(evt.timeSinceLastFrame);
    return BaseApplication::frameRenderingQueued(evt);
    
}

bool GameProject::keyPressed(const OIS::KeyEvent &arg)
{
    if (!mTrayMgr->isDialogVisible())
        core->injectKeyDown(arg);
    return BaseApplication::keyPressed(arg);
}

bool GameProject::keyReleased(const OIS::KeyEvent& evt)
{
    if (!mTrayMgr->isDialogVisible())
        core->injectKeyUp(evt);
    return BaseApplication::keyReleased(evt);
}

bool GameProject::mouseMoved(const OIS::MouseEvent& evt)
{
    if (!mTrayMgr->isDialogVisible())
        core->injectMouseMove(evt);
    return BaseApplication::mouseMoved(evt);
}

bool GameProject::mousePressed(const OIS::MouseEvent& arg, OIS::MouseButtonID id)
{
    if (!mTrayMgr->isDialogVisible())
        core->injectMouseDown(arg, id);
    return BaseApplication::mousePressed(arg, id);
}

void GameProject::createGrassMesh(void)
{
	//declare all of our grass variables
	const float width = 25.0f;
	const float height = 30.0f;
 
	Ogre::ManualObject grass("GrassObject");
 
	Ogre::Vector3 vec(width / 2, 0, 0);
	Ogre::Quaternion rot;
	rot.FromAngleAxis(Ogre::Degree(60), Ogre::Vector3::UNIT_Y);
 
	//start defining our manual object
	grass.begin("Examples/GrassBlades", Ogre::RenderOperation::OT_TRIANGLE_LIST);
 
	//define the 4 vertices of our quad and set to the texture coordinates
	for(int i = 0; i < 3; ++i)
	{
		grass.position(-vec.x, height, -vec.z);
		grass.textureCoord(0, 0);
 
		grass.position(vec.x, height, vec.z);
		grass.textureCoord(1, 0);
 
		grass.position(-vec.x, 0, -vec.z);
		grass.textureCoord(0, 1);
 
		grass.position(vec.x, 0, vec.z);
		grass.textureCoord(1, 1);
 
		int offset = i * 4;
 
		grass.triangle(offset, offset + 3, offset + 1);
		grass.triangle(offset, offset + 2, offset + 3);
 
		//rotate the next quad
		vec = rot * vec;
	}
	grass.end();
 
	//create an actual mesh out of this object
	grass.convertToMesh("GrassBladesMesh");
}

//-------------------------------------------------------------------------------------
void GameProject::createScene(void)
{    
    core->create(mCamera);
    createGrassMesh();
    mSceneMgr->setAmbientLight(Ogre::ColourValue::White);

    Ogre::Plane plane;
	plane.normal = Ogre::Vector3::UNIT_Y;
	plane.d = 0;
 
    mCameraMan->setStyle(OgreBites::CS_MANUAL);

	Ogre::MeshManager::getSingleton().createPlane("floor", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, 450.0f, 450.0f, 10, 10, true, 1, 50.0f, 50.0f, Ogre::Vector3::UNIT_Z);
	Ogre::Entity* planeEnt = mSceneMgr->createEntity("plane", "floor");
	planeEnt->setMaterialName("Examples/Rockwall");
	planeEnt->setCastShadows(false);
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(planeEnt);

    Light* light = mSceneMgr->createLight();
	light->setType(Light::LT_POINT);
	light->setPosition(-10, 40, 20);
	light->setSpecularColour(ColourValue::White);
 
  /*  
	Ogre::Entity* grass = mSceneMgr->createEntity("grass", "GrassBladesMesh");
	Ogre::StaticGeometry* sg = mSceneMgr->createStaticGeometry("GrassArea");
 
	const int size = 375;
	const int amount = 20;
 
	sg->setRegionDimensions(Ogre::Vector3(size, size, size));
	sg->setOrigin(Ogre::Vector3(-size/2, 0, -size/2));
 
	for(int x = -size / 2; x < size /2; x += (size/amount))
	{
		for(int z = -size / 2; z < size / 2; z += (size/amount))
		{
			Ogre::Real r = size / float(amount / 2);
			Ogre::Vector3 pos(x + Ogre::Math::RangeRandom(-r, r), 0, z + Ogre::Math::RangeRandom(-r, r));
			Ogre::Vector3 scale(1, Ogre::Math::RangeRandom(0.9f, 1.1f), 1);
			Ogre::Quaternion orientation;
 
			orientation.FromAngleAxis(Ogre::Degree(Ogre::Math::RangeRandom(0, 359)), Ogre::Vector3::UNIT_Y);
 
			sg->addEntity(grass, pos, orientation, scale);
		}
		sg->build();
	}
    */

}



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        GameProject app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
