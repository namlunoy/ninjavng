#ifndef _TAGS_
#define _TAGS_

#include <map>
#include <iostream>

using namespace std;

class Tags
{
private:
	static map<int, string> m;
public:
	static string getName(int tag)
	{
		switch (tag)
		{
		case Tags::GROUND:
			return "GROUND";
		case Tags::NINJA:
			return "NINJA";
		default:
			break;

		}
	}
	static const int GROUND = 11;
	static const int NINJA = 12;
	Tags();
	~Tags();
};

#endif

