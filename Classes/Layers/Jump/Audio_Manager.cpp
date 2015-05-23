#include "Audio_Manager.h"


Audio_Manager::Audio_Manager()
{
}

Audio_Manager::~Audio_Manager()
{
}

bool Audio_Manager::init()
{
	if (!Layer::init()) return false;


	return true;
}

Audio_Manager * Audio_Manager::createAudioLayer()
{
	Audio_Manager * layer = new Audio_Manager();
	layer->init();
	layer->autorelease();
	return layer;
}