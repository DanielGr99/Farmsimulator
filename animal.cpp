#include "animal.h"
#include "header.h"

unsigned int animal::reproduce(unsigned int animals,unsigned int maxanimals)
{
	if (nanimal >= 2)
	{
		unsigned int remaining = nanimal % 4;		//Der Rest der nachher abgezogen wird um einen Fehler zu vermeiden
		unsigned int i = createrandom(0, ((nanimal-remaining) / 4 * reproduction));
		if (maxanimals>=animals+i)
		{
			nanimal += i;
			return i;
		}
		else
			return 0;
	}
	else
		return 0;
}
unsigned int animal::death()
{
	if (nanimal >= deathday)
	{
		unsigned int remaining = nanimal % deathday;	//Der Rest der nachher abgezogen wird um einen Fehler zu vermeiden
		unsigned int i = createrandom(0, ((nanimal-remaining) / deathday));
		nanimal -= i;
		return i;
	}
	else
		return 0;
}