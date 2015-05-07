#include "Generator.h"

Generator::Generator(PhiTieuLayer* l) {
	layer = l;
	this->autorelease();
	isGenerate = true;
}
Generator::~Generator() {
	counter = 0;
}

void Generator::sinhJump() {
	if(isGenerate && counter < MAX)
	{
		layer->addChild(Enemy_Jump::create(1));
		counter++;
		log("counter : %d",counter);
	}
}

void Generator::sinhRun() {
	if(isGenerate && counter < MAX)
	{
		layer->addChild(Enemy_Run::create(1));
		counter++;
		log("counter : %d",counter);
	}
}
void Generator::Generate(int level) {
	counter = 0;

	switch(level)
	{
	case 1:
		SinhLevel_1();
		break;
	default:
		SinhLevel_1();
		break;
	}
}

void Generator::SinhLevel_1() {
	MAX = 30;
	log("MAX : %d",MAX);
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

void Generator::SinhLevel_2() {
}

void Generator::SinhLevel_3() {
}

void Generator::SinhLevel_4() {
}

void Generator::SinhLevel_5() {
}

void Generator::stop() {
	isGenerate = false;
}
