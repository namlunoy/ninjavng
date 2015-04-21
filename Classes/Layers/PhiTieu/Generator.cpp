#include "Generator.h"

Generator::Generator(PhiTieuLayer* l) {
	layer = l;
}
Generator::~Generator() {
}

void Generator::sinhJump() {
	log("Generator::sinhJump()");
	layer->addChild(Enemy_Jump::create(1));
}

void Generator::sinhRun() {
	log("Generator::sinhRun()");
	layer->addChild(Enemy_Run::create(1));
}
void Generator::Generate() {
	log("Generator::Generate()");
	auto sinhJumpAction = CallFunc::create(
			CC_CALLBACK_0(Generator::sinhJump, this));
	auto sinhRunAction = CallFunc::create(
			CC_CALLBACK_0(Generator::sinhRun, this));

	auto delay_1 = DelayTime::create(2);
	auto delay_05 = DelayTime::create(1.5f);

	auto action_1 = RepeatForever::create(
			Sequence::createWithTwoActions(delay_1, sinhJumpAction));

	auto action_2 = RepeatForever::create(
			Sequence::createWithTwoActions(delay_05, sinhRunAction));

	auto action = Spawn::createWithTwoActions(action_1, action_2);

	this->runAction(action_1);
	this->runAction(action_2);
}
