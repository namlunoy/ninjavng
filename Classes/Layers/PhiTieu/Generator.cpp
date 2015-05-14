#include "Generator.h"
#include "Models/PhiTieu/Heart.h"

Generator* Generator::Instance = nullptr;
Generator::Generator(PhiTieuLayer* l) {
	layer = l;
	this->autorelease();
	isGenerate = true;
	Instance = this;
}
Generator::~Generator() {
	counter = 0;
}

void Generator::sinhJump() {
	// && counter < MAX
	if(isGenerate)
	{
		auto e = Enemy_Jump::create();
		layer->addChild(e);
		enemies.pushBack(e);
		counter++;
		log("counter : %d",counter);

		auto sinh = CallFunc::create(CC_CALLBACK_0(Generator::sinhJump, this));
		auto delay = DelayTime::create(random(1.0f,2.0f));
		this->runAction(Sequence::createWithTwoActions(delay, sinh));
	}
}

void Generator::sinhRun() {
	//&& counter < MAX
	if(isGenerate )
	{
		auto e = Enemy_Run::create();
		layer->addChild(e);
		enemies.pushBack(e);
		counter++;
		log("counter : %d",counter);

		auto sinh = CallFunc::create(CC_CALLBACK_0(Generator::sinhRun, this));
		auto delay = DelayTime::create(random(1.0f,2.0f));
		this->runAction(Sequence::createWithTwoActions(delay, sinh));
	}
}
void Generator::sinhHeart() {
	if(isGenerate)
	{
		auto h = Heart::create();
		this->addChild(h);
	}
}

void Generator::Generate(int level) {
	Instance = this;
	counter = 0;
	Enemy_Run::reset();
	Enemy_Jump::reset();
	sinhRun();
	sinhJump();
}


void Generator::gameOver() {
	isGenerate = false;
	for(Enemy* e : enemies)
		e->removeFromParent();
}
