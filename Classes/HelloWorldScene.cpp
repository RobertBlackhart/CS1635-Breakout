#include "HelloWorldScene.h"
#include "Breakout.h"
#include "Options.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
CCScene* HelloWorld::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();
	scene->addChild(layer);

	// return the scene
	return scene;
}

CCSprite *newGameButton;
CCSprite *optionButton;
bool sound = true;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 0))) //RGBA
		return false;

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite* background = CCSprite::create("background.png");
	background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	background->setScaleX(visibleSize.width / background->getContentSize().width);
	background->setScaleY(visibleSize.height / background->getContentSize().height);
	this->addChild(background);

	CCSprite * logo = CCSprite::create("logo1.png");
	float x = visibleSize.width / 2;
	float y = visibleSize.height - logo->getContentSize().height / 2;
	logo->setPosition(ccp(x, y));
	this->addChild(logo);

	CCLabelTTF* byLine = CCLabelTTF::create("Robert McDermot", "Syncopate", 36);
	x = visibleSize.width - byLine->getContentSize().width / 2;
	y = byLine->getContentSize().height / 2;
	byLine->setPosition(ccp(x, y));
	byLine->setColor(ccORANGE);
	this->addChild(byLine);

	newGameButton = CCSprite::create("start_game.png");
	newGameButton->setPosition(ccp(visibleSize.width / 2, visibleSize.height * .6));
	this->addChild(newGameButton);

	optionButton = CCSprite::create("options.png");
	optionButton->setPosition(ccp(visibleSize.width / 2, visibleSize.height * .3));
	this->addChild(optionButton);

	this->setTouchEnabled(true);
	return true;
}
void HelloWorld::update(float dt) {}
void HelloWorld::onEnter()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

}
void HelloWorld::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
}
bool HelloWorld::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint location = touch->getLocationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);
	if(newGameButton->boundingBox().containsPoint(location))
	{
		CCScene *newScene = Game::scene();
		CCDirector::sharedDirector()->replaceScene(newScene);
	}
	else if(optionButton->boundingBox().containsPoint(location))
	{
		CCScene *newScene = Options::scene();
		CCDirector::sharedDirector()->replaceScene(newScene);
	}

	return true;
}
void HelloWorld::ccTouchMoved(CCTouch* touch, CCEvent* event){}
void HelloWorld::ccTouchEnded(CCTouch* touch, CCEvent* event){}

void HelloWorld::touchDelegateRetain()
{
	this->retain();
}
void HelloWorld::touchDelegateRelease()
{
	this->release();
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
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

