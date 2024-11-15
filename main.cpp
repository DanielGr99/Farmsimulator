#include <iostream>
#include "animal.h"
#include "money.h"
#include "farm.h"

using namespace std;

int menu(long money, unsigned int animals, unsigned int maxanimals);

int main()
{
	//Spiel initialisieren
	farm farmone(100, 0);
	animal cow(0, 10, 2);
	animal sheep(0, 8, 2);
	animal chicken(0, 5, 3);
	money bank(100000);


	menu(bank.getmoney(),0,100);
	
	int i = cow.reproduce();
	int j= cow.death();
	unsigned int cows = cow.getanimal();
	cout << cows << endl;
	cout << i << " Tiere wurden geboren. Und " << j << " Tiere sind gestorben." << endl;
	return 0;
}
int menu(long money, unsigned int animals, unsigned int maxanimals)
{
	int i;
	cout << "\t\t\t\tGeld: " << money << "\t\tTiere: " << animals << "/" << maxanimals << "\n" << endl;
	cout << "Tiere kaufen(1)" << "\t\tTiere verkaufen(2)" << "\t\tFarm vergroessern(3)" << "\t\tWoche weiterschalten(4)"<<endl;
	cin >> i;
	return i;
}