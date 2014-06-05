#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

extern bool sound;
class HelloWorld : public cocos2d::CCLayerColor
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
    bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    void ccTouchMoved(CCTouch* touch, CCEvent* event);
    void ccTouchEnded(CCTouch* touch, CCEvent* event);
    void touchDelegateRetain();
    void touchDelegateRelease();
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};


#endif // __HELLOWORLD_SCENE_H__
