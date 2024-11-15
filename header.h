#ifndef _header_
#define _header_

#include <ctime>
#include <cstdlib>

int createrandom(int min, int max)
{
	srand((unsigned int)time(NULL));
	int random = min + rand() % max;
	return random;
}


#endif
