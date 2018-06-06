//
//  FirstScene.cpp
//  doudizhu
//
//  Created by mac on 18/6/4.
//
//

#include "FirstScene.hpp"
#include "frist.hpp"
Scene* FirstScene::createScene()
{
    auto scene = Scene::create();
    auto layer = FirstScene::create();
    scene->addChild(layer);
    return scene;
}
bool FirstScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    visiableSize = Director::getInstance()->getVisibleSize();
    //添加界面精灵
    auto jiemian = Sprite::create("bg.jpg");
    jiemian->setPosition(Vec2(visiableSize.width/2,visiableSize.height/2));
    this->addChild(jiemian);
    
    auto bgtext = Sprite::create("bgtext.png");
    bgtext->setPosition(Vec2(visiableSize.width/2,visiableSize.height/2));
    this->addChild(bgtext);
    
    
    //添加Loading标签
    auto label = Label::createWithSystemFont("正在加载场景...", "Marker Felt.ttf", 20);
    label->setColor(Color3B::GREEN);
    label->setAnchorPoint(Vec2(0.5, 0));
    label->setPosition(visiableSize.width/2 , 30);
    this->addChild(label);
    
    //添加进度条
    auto programer = ProgressTimer::create(Sprite::create("jindutiao.png"));
    programer->setAnchorPoint(Vec2(0.5,0));
    programer->setPosition(Vec2(visiableSize.width/2, 0));
    
    programer->setType(ProgressTimer::Type::BAR);
    programer->setMidpoint(Vec2(0, 0.5));
    programer->setBarChangeRate(Vec2(1, 0));
    programer->setScaleY(0.2);
    programer->setScaleX(2);
    this->addChild(programer,10);
    programer->setPercentage(50);
    
    auto programeAction = ProgressFromTo::create(5, 0, 100);
    auto callfunc = CallFuncN::create([=](Ref* sender){
        auto scene = Frist::createScene();
        auto transionScene = TransitionFadeDown::create(1, scene);
        Director::getInstance()->replaceScene(transionScene);
    });
    auto sequence = Sequence::create(programeAction,callfunc, NULL);
    programer->runAction(sequence);
    
    
    return true;
}

void FirstScene::startBtnOnClick(Ref* sender)
{
    
    if (isBtnClickFirst) {
        
    }
    isBtnClickFirst = false;
}

