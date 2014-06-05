#ifndef __Game_H__
#define __Game_H__

#include "cocos2d.h"
USING_NS_CC;
//extern bool sound;
class Game : public cocos2d::CCLayer
{

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	void update(float dt);

	void onEnter();
    void onExit();

    bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

    void touchDelegateRetain();
    void touchDelegateRelease();
    // implement the "static node()" method manually
    CREATE_FUNC(Game);
};

#endif // __Game_H__
