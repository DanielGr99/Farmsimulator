#ifndef _header_
#define _header_

#include <ctime>
#include <cstdlib>

int createRandom(int min, int max)
{
	srand((unsigned int)time(NULL));
	int random = min + rand() % max;
	return random;
}

#endif
