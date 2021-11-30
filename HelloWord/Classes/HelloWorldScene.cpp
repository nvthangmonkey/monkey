#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include"GameScene.h"
#include "cocos2d.h"
#include"cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

   
    //    // Add label "PLAY" with callback HelloWorld::play
    auto play = MenuItemLabel::create(Label::createWithTTF("PLAY", "fonts/Marker Felt.ttf", 40),
        CC_CALLBACK_1(HelloWorld::play, this));
    //// Assert that play is not null
    CCASSERT(play != nullptr, "problem loading fonts/Marker Felt.ttf");

    //// Position PLAY in the middle of screen
    play->setPosition((Vec2(visibleSize) - origin) / 2);

    //// Add PLAY to menu
    menu->addChild(play);

    auto mainMenu = CSLoader::getInstance()->createNode("csb/MainMenu.csb");
    this->addChild(mainMenu);
    auto button = mainMenu->getChildByName<ui::Button*>("button_play");
    button->setPressedActionEnabled(true);
    button->addClickEventListener([=](Ref*) {
        cocos2d::log("play_play");
        Director::getInstance()->replaceScene(GameScene::createScene());
        });


   


    return true;
}


void HelloWorld::menuCloseCallback(cocos2d::Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}

void HelloWorld::play(cocos2d::Ref * pSender)
{
    Director::getInstance()->replaceScene(GameScene::createScene());
}
