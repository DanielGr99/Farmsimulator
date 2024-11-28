#include "animal.h"
#include "header.h"

unsigned int Animal::reproduce(unsigned int animals,unsigned int maxAnimals)
{
	if (nAnimal >= 2)
	{
		unsigned int remaining = nAnimal % 4;		//Der Rest der nachher abgezogen wird um einen Fehler zu vermeiden
		unsigned int i = createRandom(0, ((nAnimal-remaining) / 4 * reproduction));
		if (maxAnimals>=animals+i)
		{
			nAnimal += i;
			return i;
		}
		else
			return 0;
	}
	else
		return 0;
}
unsigned int Animal::death()
{
	if (nAnimal >= deathday)
	{
		unsigned int remaining = nAnimal % deathday;	//Der Rest der nachher abgezogen wird um einen Fehler zu vermeiden
		unsigned int i = createRandom(0, ((nAnimal-remaining) / deathday));
		nAnimal -= i;
		return i;
	}
	else
		return 0;
}