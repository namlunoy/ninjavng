
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
		default:
			break;

		}
	}
	static const int GROUND = 11;
	static const int NINJA = 12;
	static const int ENEMY = 13;
	static const int SHURIKEN = 14;

	Tags();
	~Tags();
};

#endif /* UTILITY_TAG_H_ */