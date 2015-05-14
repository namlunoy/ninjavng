#include "Generator.h"
#include "Models/PhiTieu/Item.h"

Generator* Generator::Instance = nullptr;
Generator::Generator(PhiTieuLayer* l) {
	layer = l;
	//hud = h;
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
void Generator::sinhItem() {
	if(isGenerate)
	{
		auto h = random(1,2) == 1 ? Item::create(Tags::HEART) : Item::create(Tags::ITEM);
		if (layer != nullptr)
			layer->addChild(h);

		auto move = MoveTo::create(5.0f,Vec2(0,Config::screenSize.height - 100));
		h->runAction(move);

		auto sinh = CallFunc::create(CC_CALLBACK_0(Generator::sinhItem, this));
		auto delay = DelayTime::create(7);
		this->runAction(Sequence::createWithTwoActions(delay, sinh));
	}
}

void Generator::Generate(int level) {
	Instance = this;
	counter = 0;
	Enemy_Run::reset();
	Enemy_Jump::reset();
	sinhRun();
	sinhJump();
	sinhItem();
}



void Generator::gameOver() {
	isGenerate = false;
	for(Enemy* e : enemies)
		e->removeFromParent();
}
