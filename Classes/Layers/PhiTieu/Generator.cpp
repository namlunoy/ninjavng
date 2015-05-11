#include "Generator.h"

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
	if(isGenerate && counter < MAX)
	{
		auto e = Enemy_Jump::create();
		layer->addChild(e);
		enemies.push_back(e);
		e->stt = counter;
		counter++;
		log("counter : %d",counter);
	}
}
void Generator::SetEnemyNull(int stt)
{
	enemies[stt] = nullptr;
}
void Generator::sinhRun() {
	if(isGenerate && counter < MAX)
	{
		auto e = Enemy_Run::create();
		layer->addChild(e);
		enemies.push_back(e);
		e->stt = counter;
		counter++;
		log("counter : %d",counter);
	}
}
void Generator::Generate(int level) {
	Instance = this;
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

	auto delay_jump = DelayTime::create(2);
	auto delay_run = DelayTime::create(1);

	auto action_1 = RepeatForever::create(
		Sequence::createWithTwoActions(delay_jump, sinhJumpAction));

	auto action_2 = RepeatForever::create(
		Sequence::createWithTwoActions(delay_run, sinhRunAction));

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
	//Huy taon bo enemies
	for (int i = 0; i < enemies.size(); i++)
		if (enemies[i] != nullptr)
			enemies[i]->removeFromParent();
}
