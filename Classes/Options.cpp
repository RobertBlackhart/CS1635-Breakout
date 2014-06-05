#include "HelloWorldScene.h"
#include "Options.h"

USING_NS_CC;
CCScene* Options::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Options *layer = Options::create();
	//Game *scene = Game::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

CCSprite *soundSprite;
CCSprite *back;

bool Options::init()
{
	//////////////////////////////
    // 1. super init first
    if( !CCLayerColor::initWithColor(ccc4(0,0,204,204)))//RGBA
    {
        return false;
    }

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite* background = CCSprite::create("background.png");
	background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	background->setScaleX(visibleSize.width / background->getContentSize().width);
	background->setScaleY(visibleSize.height / background->getContentSize().height);
	this->addChild(background);

	back = CCSprite::create("back.png");
	float x = back->getContentSize().width/2;
	float y = visibleSize.height - back->getContentSize().height/2;
	back->setPosition(ccp(x, y));
	this->addChild(back);

	CCLabelTTF* byLine = CCLabelTTF::create("Robert McDermot", "Syncopate", 36);
	x = visibleSize.width - byLine->getContentSize().width/2;
	y = byLine->getContentSize().height/2;
	byLine->setPosition(ccp(x, y));
	byLine->setColor(ccORANGE);
	this->addChild(byLine);
	
	if(!sound)
		soundSprite = CCSprite::create("sound_off.png");
	else
		soundSprite = CCSprite::create("sound_on.png");
	soundSprite->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	this->addChild(soundSprite);
    
    return true;
}
void Options::update(float dt){
}
void Options::onEnter(){
    CCDirector* pDirector = CCDirector::sharedDirector();
	CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(Options::update),this,0,false);
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

}
void Options::onExit(){
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
}
bool Options::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	if (soundSprite->boundingBox().containsPoint(location))
	{
		if(!sound)
		{
			sound = true;
			soundSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("sound_on.png"));
		}
		else
		{
			sound = false;
			soundSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("sound_off.png"));
		}
	}
	else if(back->boundingBox().containsPoint(location))
	{
		CCScene *pScene = HelloWorld::scene();
		CCDirector::sharedDirector()->replaceScene(pScene);
	}

    return true;
}
void Options::ccTouchMoved(CCTouch* touch, CCEvent* event){
    //do what you want
}
void Options::ccTouchEnded(CCTouch* touch, CCEvent* event){
//do your job here
}
void Options::touchDelegateRetain(){
	this->retain();
}
void Options::touchDelegateRelease(){
	this->release();
}
void Options::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

