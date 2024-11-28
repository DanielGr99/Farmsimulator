#ifndef _animal_
#define _animal_

class Animal
{
private:
	//Anzahl der Tiere
	unsigned int nAnimal;	
	//Nach wievielen Tagen ein Tier stirbt
	unsigned int deathday;			
	//Vermehrungsrate des Tieres
	unsigned int reproduction;		
	//Preis des Tieres
	long priceBuy;
	//Verkaufspreis des Tieres
	long priceSell;
public:
	//Konstruktor
	Animal(unsigned int nnimal, unsigned int dday, unsigned int reprod, unsigned int priceb, unsigned int prices) { nAnimal = nnimal; deathday = dday; reproduction = reprod; priceBuy = priceb; priceSell = prices; }
	// Tiere hinzufügen
	void setnAnimal(int n) { nAnimal += n; }
	unsigned int getAnimal() const { return nAnimal; }
	unsigned int getDeathday() const { return deathday; }
	unsigned int getReproduction() const { return reproduction; }
	long getPriceBuy() const { return priceBuy; }
	long getPriceSell() const { return priceSell; }
	unsigned int reproduce(unsigned int animals, unsigned int maxanimals);
	unsigned int death();
};

#endif
