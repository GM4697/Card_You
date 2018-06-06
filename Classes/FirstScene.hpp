//
//  FirstScene.hpp
//  doudizhu
//
//  Created by mac on 18/6/4.
//
//

#ifndef FirstScene_hpp
#define FirstScene_hpp

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGui.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class FirstScene :public Layer
{
public:
    static Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(FirstScene);
    void startBtnOnClick(Ref* sender);
private:
    Size visiableSize;
    bool isBtnClickFirst;
};

#endif /* FirstScene_hpp */
