#ifndef _farm_
#define _farm_

class farm
{
private:
	unsigned int maxanimals;				//max. Anzahl an Tieren die Platz haben
	unsigned int animals;					//Anzahl der Tiere auf dem Bauernhof
public:
	//Konstruktor
	farm(unsigned int manimals, unsigned int nanimals) { maxanimals = manimals; animals = nanimals; }
	//Maximale Tiere erh�hen
	void raisemaxanimals(unsigned int a) { maxanimals += a; }
	//Maximale Tiere vermindern
	void reducemaxanimals(unsigned int a) { maxanimals -= a; }
	//Tiere auf der Farm
	void setanimals(unsigned int i) { animals = i; }
	//Tiere auf der Farm anzeigen
	unsigned int getanimals() { return animals; }
	//Maximale Tierkapazit�t anzeigen
	unsigned int getmaxanimals() { return maxanimals; }
};

#endif
