#pragma once
#include <iostream>

using namespace std;
const int evNothing = 0;
const int cmGet = 3;
const int cmShow = 4;

struct TEvent
{
	int what;
	union
	{
		int command;

		struct

		{
			int message;
			int a;
		};
	};
};

