#include <iostream>
#include "animal.h"
#include "money.h"
#include "farm.h"

using namespace std;

#define clearc system("cls")				//Konsole leeren

int menu(long money, unsigned int animals, unsigned int maxanimals, int& week, animal& cow, animal& sheep, animal& chicken, int& births, int& deaths);
void buyanimal(animal &cow,animal &sheep, animal &chicken, money &bank, farm& farmone);
void sellanimal(animal& cow, animal& sheep, animal& chicken, money& bank);
void buyfarmspace(money& bank,farm& farmone);
void week(animal& cow, animal& sheep, animal& chicken, unsigned int maxanimals,int &births, int &deaths);

int main()
{
	unsigned int animals = 0;
	int nweek = 1,i =0, births =0, deaths=0;					//Wochen die vergangen sind, Menü, Tode und Geburten
	//Spiel initialisieren
	farm farmone(100, 0);
	animal cow(0, 7, 2, 10000,8000);
	animal sheep(0, 5, 2,8000,5000);
	animal chicken(0, 3, 3,500,300);
	money bank(100000);
	do
	{
		//Tiere zählen
		animals = cow.getanimal() + sheep.getanimal() + chicken.getanimal();
		farmone.setanimals(animals);
		// Menü drucken
		i = menu(bank.getmoney(), animals, farmone.getmaxanimals(), nweek,cow,sheep,chicken,births,deaths);
		if (i == 1)
		{
			buyanimal(cow, sheep, chicken, bank, farmone);
		}
		else if (i == 2)
		{
			sellanimal(cow, sheep, chicken, bank);
		}
		else if (i == 3)
		{
			buyfarmspace(bank, farmone);
		}
		else if (i == 4)
		{
			births = 0;
			deaths = 0;
			week(cow, sheep, chicken, farmone.getmaxanimals(),births,deaths);
			++nweek;
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
int menu(long money, unsigned int animals, unsigned int maxanimals, int &week, animal &cow, animal &sheep, animal &chicken, int &births, int &deaths)
{
	clearc;
	int i;
	cout << "\t\t\tGeld: " << money << "\t\tTiere: " << animals << "/" << maxanimals << "\t\tWoche: " << week << endl;
	cout << "\t\t\tKuehe: " << cow.getanimal() << "\t\tSchafe: " << sheep.getanimal() << "\t\tHuehner: " << chicken.getanimal() << endl;
	cout << "\t\t\tGeburten diese Woche: " << births << "\t\t\tTode diese Woche: " << deaths << "\n" <<endl;
	cout << "Tiere kaufen(1)" << "\t\tTiere verkaufen(2)" << "\tFarm vergroessern(3)" << "\tWoche weiterschalten(4)"<<"\t\tSpiel beenden(0)" << endl;
	cin >> i;
	return i;
}
void buyanimal(animal& cow, animal& sheep, animal& chicken, money& bank, farm &farmone)
{
	clearc;
	int i=0,j=0;
	cout << "\t\t\tWelches Tier soll gekauft werden?\n" << endl;
	cout << "\tKuehe(1) Preis:10000\t\tSchafe(2) Preis:8000\t\tHuehner(3) Preis:500" << endl;
	cin >> i;
	clearc;
	cout << "Wieviele Tiere sollen gekauft werden?: ";
	cin >> j;
	if (i == 1 && bank.getmoney() >= j * cow.getpricebuy()&&farmone.getmaxanimals() >= (farmone.getanimals()+j))
	{
		cow.setnanimal(j);
		bank.reducemoney(cow.getpricebuy() * j);
	}
	else if (i == 2 && bank.getmoney() >= j * sheep.getpricebuy() && farmone.getmaxanimals() >= (farmone.getanimals() + j))
	{
		sheep.setnanimal(j);
		bank.reducemoney(sheep.getpricebuy() * j);
	}
	else if (i == 3 && bank.getmoney() >= j * chicken.getpricebuy() && farmone.getmaxanimals() >= (farmone.getanimals() + j))
	{
		chicken.setnanimal(j);
		bank.reducemoney(chicken.getpricebuy() * j);
	}
	else
	{
		cout << "\nAktion nicht moeglich!" << endl;
		delay(10);
	}
}
void sellanimal(animal& cow, animal& sheep, animal& chicken, money& bank)
{
	clearc;
	int i = 0, j = 0;
	cout << "\t\t\tWelches Tier soll verkauft werden?\n" << endl;
	cout << "\tKuehe(1) Verkaufspreis:8000\t\tSchafe(2) Verkaufspreis:5000\t\tHuehner(3) Verkaufspreis:300" << endl;
	cin >> i;
	clearc;
	cout << "Wieviele Tiere sollen verkauft werden?: ";
	cin >> j;
	if (i == 1&&cow.getanimal()>=j)
	{
		cow.setnanimal(-j);
		bank.raisemoney(cow.getpricesell() * j);
	}
	else if (i == 2 && sheep.getanimal() >= j)
	{
		sheep.setnanimal(-j);
		bank.raisemoney(sheep.getpricesell() * j);
	}
	else if (i == 3 && chicken.getanimal() >= j)
	{
		chicken.setnanimal(-j);
		bank.raisemoney(chicken.getpricesell() * j);
	}
	else
	{
		cout << "\nAktion nicht moeglich!" << endl;
		delay(10);
	}
}
void buyfarmspace(money& bank, farm& farmone)
{
	char c;
	clearc;
	cout << "Die maximale Tieranzahl, fuer 100000, um 10 erhoehen?(J/N): ";
	cin >> c;
	if ((c == 'j' || c == 'J') && bank.getmoney() >= 100000)
	{
		farmone.raisemaxanimals(10);
		bank.reducemoney(100000);
	}
	else
	{
		cout << "\nAktion nicht moeglich!" << endl;
		delay(10);
	}
}
void week(animal& cow, animal& sheep, animal& chicken,unsigned int maxanimals, int &births, int &deaths)
{
	unsigned int animals = cow.getanimal() + sheep.getanimal() + chicken.getanimal();
	births += cow.reproduce(animals,maxanimals);
	animals = cow.getanimal() + sheep.getanimal() + chicken.getanimal();
	births += sheep.reproduce(animals, maxanimals);
	animals = cow.getanimal() + sheep.getanimal() + chicken.getanimal();
	births += chicken.reproduce(animals, maxanimals);
	deaths += cow.death();
	deaths += sheep.death();
	deaths += chicken.death();
}
