#ifndef _money_
#define _money_

class Money
{
private:
	long nMoney;						//Menge des Geldes

public:
	//Konstruktor
	Money(long nmon) { nMoney = nmon; }
	void raiseMoney(long a) { nMoney += a; }				//Menge des Geldes erhöhen
	void reduceMoney(long a) { nMoney -= a; }				//Menge des Geldes vermindern
	long getMoney() const { return nMoney; }						//Menge des Geldes anzeigen
};

#endif
