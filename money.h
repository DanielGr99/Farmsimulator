#ifndef _money_
#define _money_

class money
{
private:
	long nmoney;						//Menge des Geldes

public:
	//Konstruktor
	money(long nmon) { nmoney = nmon; }
	void raisemoney(long a) { nmoney += a; }				//Menge des Geldes erhöhen
	void reducemoney(long a) { nmoney -= a; }				//Menge des Geldes vermindern
	long getmoney() { return nmoney; }						//Menge des Geldes anzeigen
};

#endif
