/*
 * Tags.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef UTILITY_TAGS_H_
#define UTILITY_TAGS_H_
#include <iostream>
using namespace std;
class Tags {
private:

public:
	static string getName(int tag)
	{
		switch (tag)
		{
		case Tags::GROUND:
			return "GROUND";
		case Tags::NINJA:
			return "NINJA";
		case Tags::SHURIKEN:
			return "SHURIKEN";
		case Tags::ENEMY:
			return "ENEMY";
		case Tags::TARGET:
			return "TARGET";
		case Tags::HEART:
			return "HEART";
		case Tags::ITEM:
			return "ITEM";
		default:
			break;

		}
	}
	static const int GROUND = 11;
	static const int NINJA = 12;
	static const int ENEMY = 13;
	static const int SHURIKEN = 14;
	static const int TARGET = 15;
	static const int HEART = 16;
	static const int ITEM = 17;
	Tags();
	~Tags();
};

#endif /* UTILITY_TAG_H_ */
