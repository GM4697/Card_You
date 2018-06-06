//
//  frist.hpp
//  Card_You
//
//  Created by Admin on 18/6/4.
//
//

#ifndef frist_hpp
#define frist_hpp

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGui.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

class Frist:public Layer{
    Size visiableSize;
public:
    static Scene * createScene();
    bool init();
    CREATE_FUNC(Frist);
};


#endif /* frist_hpp */
