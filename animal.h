#ifndef _animal_
#define _animal_

class animal
{
private:
	//Anzahl der Tiere
	unsigned int nanimal;	
	//Nach wievielen Tagen ein Tier stirbt
	unsigned int deathday;			
	//Vermehrungsrate des Tieres
	unsigned int reproduction;							
public:
	//Konstruktor
	animal(unsigned int nnimal, unsigned int dday, unsigned int reprod) { nanimal = nnimal; deathday = dday; reproduction = reprod; }
	// Tiere hinzufügen
	void setnanimal(int n) { nanimal += n; }
	unsigned int getanimal() { return nanimal; }
	unsigned int getdeathday() { return deathday; }
	unsigned int getreproduction() { return reproduction; }
	unsigned int reproduce();
	unsigned int death();
};

#endif
