//
//  frist.cpp
//  Card_You
//
//  Created by Admin on 18/6/4.
//
//

#include "frist.hpp"
#include "GameScene.h"
Scene * Frist::createScene()
{
    auto scene = Scene::create();
    auto layer = Frist::create();
    scene->addChild(layer);
    return scene;
}
bool Frist::init()
{
    if (!Layer::init()) {
        return false;
    }
    visiableSize = Director::getInstance()->getVisibleSize();
    auto jiemian = Sprite::create("bg.jpg");
    jiemian->setPosition(Vec2(visiableSize.width/2,visiableSize.height/2));
    this->addChild(jiemian);
    
    auto bgtext = Sprite::create("bgtext.png");
    bgtext->setPosition(Vec2(visiableSize.width/2,visiableSize.height/2));
    this->addChild(bgtext);
    
    auto play = Button::create("kaishi.jpg");
    play->setScale(1.3);
    play->setPosition(Vec2(visiableSize.width*0.4,visiableSize.height*0.3));
    this->addChild(play);
    play->addClickEventListener([=](Ref*sendf){
        auto scene = GameScene::scene();
        auto transionScene = TransitionFadeDown::create(1, scene);
        Director::getInstance()->replaceScene(transionScene);
    });
    
    auto shezhi = Button::create("shezhi.jpg");
    shezhi->setScale(1.3);
    shezhi->setPosition(Vec2(visiableSize.width*0.6,visiableSize.height*0.3));
    this->addChild(shezhi);
    
    auto tuichu = Button::create("tuichu.jpg");
    tuichu->setScale(1.3);
    tuichu->setPosition(Vec2(visiableSize.width/2,visiableSize.height*0.2));
    this->addChild(tuichu);
    tuichu->addClickEventListener([=](Ref*){
        exit(0);
    });
    
    
    return true;
}