#include "Player.h"
#include "Poker.h"
Player::Player():m_isCall(false),m_iCallNum(0),m_isDiZhu(false),m_isOutPk(false)
{
	m_arrPk = __Array::create(); //手里拥有的扑克牌的存储数组
	m_arrPk->retain();
}

Player::~Player()
{
	CC_SAFE_RELEASE(m_arrPk);
}
//玩家种类:0为玩家，1为电脑，2为显示的三张牌,3为玩家要出的牌，4为电脑1要出的牌，5为电脑2要出的牌
void Player::updatePkWeiZhi(){
	Size size = Director::getInstance()->getVisibleSize();
	int x,y;
	if(m_iPlayerClass == 0 || m_iPlayerClass == 3)
	{
		x = size.width/2-((m_arrPk->count()-1)*pkJianJu+pkWidth)/2;
		y = m_point.y;
	}
	else if(m_iPlayerClass == 1 || m_iPlayerClass == 4 || m_iPlayerClass == 5)
	{
		x = m_point.x;
		y = m_point.y;
	}
	else if(m_iPlayerClass == 2)
	{
		x = size.width/2-(m_arrPk->count()*pkWidth+(m_arrPk->count()-1)*pkJianJu)/2;
		y = m_point.y;
	}
	int num = 0;
	Ref* object;
	//对牌进行排序
    //玩家种类:0为玩家，1为电脑，2为显示的三张牌,3为玩家要出的牌，4为电脑1要出的牌，5为电脑2要出的牌
	if(m_iPlayerClass != 3 && m_iPlayerClass != 4 && m_iPlayerClass != 5)
        //冒泡排序
		for(int i=0; m_arrPk->count()!=0 && i<m_arrPk->count()-1; ++i)
		{
			for(int j=0; j<m_arrPk->count()-1-i; ++j)
			{
				Poker* pk1 = (Poker*)m_arrPk->getObjectAtIndex(j);
				Poker* pk2 = (Poker*)m_arrPk->getObjectAtIndex(j+1);
				if(pk1->getNum() < pk2->getNum())
					m_arrPk->exchangeObject(pk1,pk2);
			}
		}
	//更新位置
    //玩家种类:0为玩家，1为电脑，2为显示的三张牌,3为玩家要出的牌，4为电脑1要出的牌，5为电脑2要出的牌
	CCARRAY_FOREACH(m_arrPk,object){
		Poker* pk = (Poker*)object;
		if (m_iPlayerClass == 0 || m_iPlayerClass == 3)
		{
			pk->showFront();
			pk->setPosition(Vec2(x+num*pkJianJu+pkWidth/2,y));
		}
		else if(m_iPlayerClass == 1 || m_iPlayerClass == 4 || m_iPlayerClass == 5)
		{
			pk->showFront();
			if(m_iPlayerClass == 1)
				pk->showLast();
			pk->setPosition(Vec2(x,y-num*pkJianJu));
		}
		else if(m_iPlayerClass == 2)
		{
			pk->setPosition(Vec2(x+num*pkJianJu+num*pkWidth+pkWidth/2,y));
		}
		++num;
	}
	//改变牌的z值或牌的触摸优先
   //玩家种类:0为玩家，1为电脑，2为显示的三张牌,3为玩家要出的牌，4为电脑1要出的牌，5为电脑2要出的牌
	CCARRAY_FOREACH(m_arrPk,object){
		Poker* pk = (Poker*)object;
		//改变z值
		if (m_iPlayerClass == 1 || m_iPlayerClass == 4 || m_iPlayerClass == 5)
			pk->setZOrder(size.height - pk->getPositionY());
		if (m_iPlayerClass == 0 || m_iPlayerClass == 3)
			pk->setZOrder(pk->getPositionX());
		//改变优先级
	/*	Poker* pk1 = (Poker *)m_arrPk->objectAtIndex(i--);
		pk->setTouchPriority(pk1->getPositionX());*/
	}
}