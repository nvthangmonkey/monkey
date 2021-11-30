#include "MainMenuScene.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
#include"GameScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();

    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{

    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto mainMenu = CSLoader::getInstance()->createNode("csb/MainMenu.csb");
    this->addChild(mainMenu);
    auto button = mainMenu->getChildByName<ui::Button*>("button_play");
    button->setPressedActionEnabled(true);
    button->addClickEventListener([=](Ref*) {
        cocos2d::log("play_play");
        auto scene = GameScene::createScene();

        Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
        });

    //auto button2 = mainMenu->getChildByName<ui::Button*>("button_leaderboard");
    //button2->setPressedActionEnabled(true);
    //button2->addClickEventListener([=](Ref*) {
    //    cocos2d::log("button_leaderboard");
    //   
    //    });

    return true;
}


