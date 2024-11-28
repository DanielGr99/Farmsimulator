#include <iostream>
#include "animal.h"
#include "money.h"
#include "farm.h"

using namespace std;

#define CLEARC system("cls")				//Konsole leeren

void delay(int i);
int menu(long money, unsigned int animals, unsigned int maxAnimals, int& week, Animal& cow, Animal& sheep, Animal& chicken, int& births, int& deaths);
void buyAnimal(Animal &cow,Animal &sheep, Animal &chicken, Money &bank, Farm& farmOne);
void sellAnimal(Animal& cow, Animal& sheep, Animal& chicken, Money& bank);
void buyFarmspace(Money& bank,Farm& farmOne);
void week(Animal& cow, Animal& sheep, Animal& chicken, unsigned int maxAnimals,int &births, int &deaths);

int main()
{
	unsigned int animals = 0;
	int nWeek = 1,i =0, births =0, deaths=0;					//Wochen die vergangen sind, Menü, Tode und Geburten
	//Spiel initialisieren
	Farm farmone(100, 0);
	Animal cow(0, 7, 2, 10000,8000);
	Animal sheep(0, 5, 2,8000,5000);
	Animal chicken(0, 3, 3,500,300);
	Money bank(100000);
	do
	{
		//Tiere zählen
		animals = cow.getAnimal() + sheep.getAnimal() + chicken.getAnimal();
		farmone.setAnimals(animals);
		// Menü drucken
		i = menu(bank.getMoney(), animals, farmone.getMaxAnimals(), nWeek,cow,sheep,chicken,births,deaths);
		if (i == 1)
		{
			buyAnimal(cow, sheep, chicken, bank, farmone);
		}
		else if (i == 2)
		{
			sellAnimal(cow, sheep, chicken, bank);
		}
		else if (i == 3)
		{
			buyFarmspace(bank, farmone);
		}
		else if (i == 4)
		{
			births = 0;
			deaths = 0;
			week(cow, sheep, chicken, farmone.getMaxAnimals(),births,deaths);
			++nWeek;
		}
	} while (i != 0);
	return 0;
}
void delay(int i)
{
	unsigned long delayt = i * 500000000L;
	for (unsigned long wait = 0; wait < delayt; ++wait)
		;
}
int menu(long money, unsigned int animals, unsigned int maxAnimals, int &week, Animal &cow, Animal &sheep, Animal &chicken, int &births, int &deaths)
{
	CLEARC;
	int i;
	cout << "\t\t\tGeld: " << money << "\t\tTiere: " << animals << "/" << maxAnimals << "\t\tWoche: " << week << endl;
	cout << "\t\t\tKuehe: " << cow.getAnimal() << "\t\tSchafe: " << sheep.getAnimal() << "\t\tHuehner: " << chicken.getAnimal() << endl;
	cout << "\t\t\tGeburten diese Woche: " << births << "\t\t\tTode diese Woche: " << deaths << "\n" <<endl;
	cout << "Tiere kaufen(1)" << "\t\tTiere verkaufen(2)" << "\tFarm vergroessern(3)" << "\tWoche weiterschalten(4)"<<"\t\tSpiel beenden(0)" << endl;
	cin >> i;
	return i;
}
void buyAnimal(Animal& cow, Animal& sheep, Animal& chicken, Money& bank, Farm &farmOne)
{
	CLEARC;
	int i=0,j=0;
	cout << "\t\t\tWelches Tier soll gekauft werden?\n" << endl;
	cout << "\tKuehe(1) Preis:10000\t\tSchafe(2) Preis:8000\t\tHuehner(3) Preis:500" << endl;
	cin >> i;
	CLEARC;
	cout << "Wieviele Tiere sollen gekauft werden?: ";
	cin >> j;
	if (i == 1 && bank.getMoney() >= j * cow.getPriceBuy()&&farmOne.getMaxAnimals() >= (farmOne.getAnimals()+j))
	{
		cow.setnAnimal(j);
		bank.reduceMoney(cow.getPriceBuy() * j);
	}
	else if (i == 2 && bank.getMoney() >= j * sheep.getPriceBuy() && farmOne.getMaxAnimals() >= (farmOne.getAnimals() + j))
	{
		sheep.setnAnimal(j);
		bank.reduceMoney(sheep.getPriceBuy() * j);
	}
	else if (i == 3 && bank.getMoney() >= j * chicken.getPriceBuy() && farmOne.getMaxAnimals() >= (farmOne.getAnimals() + j))
	{
		chicken.setnAnimal(j);
		bank.reduceMoney(chicken.getPriceBuy() * j);
	}
	else
	{
		cout << "\nAktion nicht moeglich!" << endl;
		delay(10);
	}
}
void sellAnimal(Animal& cow, Animal& sheep, Animal& chicken, Money& bank)
{
	CLEARC;
	int i = 0, j = 0;
	cout << "\t\t\tWelches Tier soll verkauft werden?\n" << endl;
	cout << "\tKuehe(1) Verkaufspreis:8000\t\tSchafe(2) Verkaufspreis:5000\t\tHuehner(3) Verkaufspreis:300" << endl;
	cin >> i;
	CLEARC;
	cout << "Wieviele Tiere sollen verkauft werden?: ";
	cin >> j;
	if (i == 1&&cow.getAnimal()>=j)
	{
		cow.setnAnimal(-j);
		bank.raiseMoney(cow.getPriceSell() * j);
	}
	else if (i == 2 && sheep.getAnimal() >= j)
	{
		sheep.setnAnimal(-j);
		bank.raiseMoney(sheep.getPriceSell() * j);
	}
	else if (i == 3 && chicken.getAnimal() >= j)
	{
		chicken.setnAnimal(-j);
		bank.raiseMoney(chicken.getPriceSell() * j);
	}
	else
	{
		cout << "\nAktion nicht moeglich!" << endl;
		delay(10);
	}
}
void buyFarmspace(Money& bank, Farm& farmOne)
{
	char c;
	CLEARC;
	cout << "Die maximale Tieranzahl, fuer 100000, um 10 erhoehen?(J/N): ";
	cin >> c;
	if ((c == 'j' || c == 'J') && bank.getMoney() >= 100000)
	{
		farmOne.raiseMaxAnimals(10);
		bank.reduceMoney(100000);
	}
	else
	{
		cout << "\nAktion nicht moeglich!" << endl;
		delay(10);
	}
}
void week(Animal& cow, Animal& sheep, Animal& chicken,unsigned int maxAnimals, int &births, int &deaths)
{
	unsigned int animals = cow.getAnimal() + sheep.getAnimal() + chicken.getAnimal();
	births += cow.reproduce(animals,maxAnimals);
	animals = cow.getAnimal() + sheep.getAnimal() + chicken.getAnimal();
	births += sheep.reproduce(animals, maxAnimals);
	animals = cow.getAnimal() + sheep.getAnimal() + chicken.getAnimal();
	births += chicken.reproduce(animals, maxAnimals);
	deaths += cow.death();
	deaths += sheep.death();
	deaths += chicken.death();
}
