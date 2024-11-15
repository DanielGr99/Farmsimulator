#include "animal.h"
#include "header.h"

unsigned int animal::reproduce()
{
	if (nanimal >= 2) 
	{
		unsigned int i = createrandom(0, (nanimal / 2 * reproduction));
		nanimal += i;
		return i;
	}
}
unsigned int animal::death() 
{
	unsigned int i = createrandom(0, (nanimal / deathday));
	nanimal -= i;
	return i;
}