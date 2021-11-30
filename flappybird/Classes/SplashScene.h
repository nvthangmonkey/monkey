#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__


#include "cocos2d.h"

USING_NS_CC;

class SplashScene : public cocos2d::Scene
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();
	;
	CREATE_FUNC(SplashScene);

	cocos2d::Sprite* background;
};

#endif // !__SPLASH_SCENE_H__