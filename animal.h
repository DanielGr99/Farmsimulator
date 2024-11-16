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
	//Preis des Tieres
	long pricebuy;
	//Verkaufspreis des Tieres
	long pricesell;
public:
	//Konstruktor
	animal(unsigned int nnimal, unsigned int dday, unsigned int reprod, unsigned int priceb, unsigned int prices) { nanimal = nnimal; deathday = dday; reproduction = reprod; pricebuy = priceb; pricesell = prices; }
	// Tiere hinzufügen
	void setnanimal(int n) { nanimal += n; }
	unsigned int getanimal() { return nanimal; }
	unsigned int getdeathday() { return deathday; }
	unsigned int getreproduction() { return reproduction; }
	long getpricebuy() { return pricebuy; }
	long getpricesell() { return pricesell; }
	unsigned int reproduce(unsigned int animals, unsigned int maxanimals);
	unsigned int death();
};

#endif
