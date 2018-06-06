#include "Poker.h"
#include "Player.h"
#include "GameScene.h"
Poker::Poker():m_isSelect(false),m_isDianJi(false){

}
Poker::~Poker(){

}
Poker* Poker::create(const char *pszFileName, const Rect& rect){
	Poker* pk = new Poker();
	if (pk && pk->initWithFile(pszFileName,rect))
	{
		pk->autorelease();
		return pk;
	}
	CC_SAFE_DELETE(pk);
	return pk;
}
void Poker::onEnter(){
	Sprite::onEnter();
	//触摸响应注册
	touchListener = EventListenerTouchOneByOne::create();//创建单点触摸事件监听器
	touchListener->onTouchBegan = CC_CALLBACK_2(Poker::onTouchBegan, this);//触摸开始
	touchListener->onTouchMoved = CC_CALLBACK_2(Poker::onTouchMoved, this);//触摸移动
	touchListener->onTouchEnded = CC_CALLBACK_2(Poker::onTouchEnded, this);//触摸结束
	touchListener->setSwallowTouches(true);//不向下吞并触摸
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);//注册分发器
}
void Poker::onExit(){
	//移除触摸响应
	_eventDispatcher->removeEventListenersForTarget(this);
	Sprite::onExit();
}
bool Poker::onTouchBegan(Touch *pTouch, Event *pEvent){
	Size size = getContentSize();
	Rect rect(-size.width/2,-size.height/2,size.width,size.height);
	Point ptouch = convertTouchToNodeSpaceAR(pTouch); //由英文之意转换 触摸 到 节点空间
	if(rect.containsPoint(ptouch) && m_isDianJi)
	{
		if(!m_isSelect){
			SelectPkLuTou();
		}
		else{
			
			SelectPkSuoTou();
		}
		return true;
	}
	return false;
	//如果这里返回false触摸不被吞掉
}
void Poker::onTouchMoved(Touch *pTouch, Event *pEvent){

}
void Poker::onTouchEnded(Touch *pTouch, Event *pEvent){

}
void Poker::onTouchCancelled(Touch *pTouch, Event *pEvent){

}
void Poker::showFront(){
	if(m_huaSe != Gui)
//   setTextureRect     设置Sprite纹理(texture)的Rect尺寸
		this->setTextureRect(Rect(this->m_num*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
	else
		this->setTextureRect(Rect((this->m_num-XiaoGui)*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
}
void Poker::showLast(){
	this->setTextureRect(Rect(PaiHaoBM*pkWidth,HuaSeBM*pkHeight,pkWidth,pkHeight));
}
Poker* Poker::copy(){
	Poker* pk;
	if(m_huaSe != Gui)
		pk = Poker::create("poker.png",Rect(this->m_num*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
	else
		pk = Poker::create("poker.png",Rect((this->m_num-XiaoGui)*pkWidth,this->m_huaSe*pkHeight,pkWidth,pkHeight));
	pk->m_isDianJi = this->m_isDianJi;
	pk->m_isSelect = this->m_isSelect;
	pk->setHuaSe(this->getHuaSe());
	pk->setNum(this->getNum());
	pk->m_gameMain = this->m_gameMain;
	return pk;
}
void Poker::setTouchPriority(int num){
	_eventDispatcher->setPriority(touchListener, num);
}
void Poker::SelectPkLuTou(){
	//添加要出的牌
	this->m_isSelect = true;
	this->setPosition(Vec2(getPositionX(),getPositionY()+10));
	m_gameMain->getArrPlayerOut()->addObject(this);//玩家选择要出的牌添加到数组
	m_gameMain->PlayerOutPaiXu(m_gameMain->getArrPlayerOut());//对出的牌进行分离
    
    
}
void Poker::SelectPkSuoTou(){
	//从出牌中移除该牌
	m_isSelect = false;
	this->setPosition(Vec2(getPositionX(),getPositionY()-10));
	m_gameMain->getArrPlayerOut()->removeObject(this);//玩家选择要出的牌的数组删除该牌
}