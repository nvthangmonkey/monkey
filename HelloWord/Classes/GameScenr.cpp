#include "GameScene.h"
#include <HelloWorldScene.h>

Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	// super init()
	if (!Scene::init()) return false;

	return true;
}

