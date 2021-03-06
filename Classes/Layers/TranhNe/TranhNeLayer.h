#ifndef LAYERS_TRANHNE_TRANHNELAYER_H_
#define LAYERS_TRANHNE_TRANHNELAYER_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Scenes/HelloWorldScene.h"
#include "Models/TranhNe/Ninja_Tranh.h"
#include "Models/TranhNe/VatRoi.h"
#include "Models/TranhNe/Giun_Dat.h"
#include "Models/TranhNe/Nen.h"

USING_NS_CC;
using namespace ui;
class TranhNeLayer: public Layer 
{
private:
	bool onContactBegin(PhysicsContact &contact);
	Ninja_Tranh* Ninja_Ne;
	VatRoi* vatRoi;
	Giun_Dat* Con_Giun;
	Nen* Mat_Dat;
public:
	TranhNeLayer();
	~TranhNeLayer();
	CREATE_FUNC(TranhNeLayer);
	bool init();
	void Load_VR();
	void Load_Giun();
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
};

#endif /* LAYERS_TRANHNE_TRANHNELAYER_H_ */
