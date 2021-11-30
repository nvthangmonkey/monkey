#include"SplashScene.h"
#include <HelloWorldScene.h>
#include<iostream>
Scene* SplashScene::createScene()
{
	return SplashScene::create();
}

bool SplashScene::init()
{
	// super init()
	if (!Scene::init()) return false;


	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	background = Sprite::create("background.png");
	background->setPosition(origin + visibleSize / 2);
	addChild(background);

	return true;
}
