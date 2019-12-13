#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

struct Buyers
{
	char surname[50];
	char name[50];
	char patronymic[50];
	char city[50];
	char street[50];
	int housenumber;
	int flatnumber;
	int cardnumber;
	int purchasecode;
};

struct Team
{
	Buyers tra[3];
};

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Team BuyersTeam1 = {};
	int b = 0;
	int col;
	cout << "Enter the number of buyers :" << endl;
	cin >> col;
	for (int i = 0; i < col; i++)
	{
		Buyers newBuyer = {};

		cout << "Enter new Buyer surname: " << "\n";

		getchar();

		cin.getline(newBuyer.surname, 50);

		cout << "Enter new Buyer name: " << "\n";

		cin.getline(newBuyer.name, 50);

		cout << "Enter new Buyer patronymic: " << "\n";

		cin.getline(newBuyer.patronymic, 50);

		cout << "Enter new Buyer city: " << "\n";

		cin.getline(newBuyer.city, 50);

		cout << "Enter new Buyer street: " << "\n";

		cin.getline(newBuyer.street, 50);

		cout << "Enter new Buyer house number: " << "\n";

		cin >> newBuyer.housenumber;

		cout << "Enter new Buyer flat number: " << "\n";

		cin >> newBuyer.flatnumber;

		cout << "Enter new Buyer card number: " << "\n";

		cin >> newBuyer.cardnumber;

		cout << "Enter new Buyer purchase code: " << "\n";

		cin >> newBuyer.purchasecode;

		BuyersTeam1.tra[i] = newBuyer;

		b++;
	}
	ofstream text;
	text.open("textNew", ofstream::app);
	if (!text.is_open())
	{
		cout << "error";
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{

			text << BuyersTeam1.tra[i].surname << "\n";
			text << BuyersTeam1.tra[i].name << "\n";
			text << BuyersTeam1.tra[i].patronymic << "\n";
			text << BuyersTeam1.tra[i].city << "\n";
			text << BuyersTeam1.tra[i].street << "\n";
			text << BuyersTeam1.tra[i].housenumber << "\n";
			text << BuyersTeam1.tra[i].flatnumber << "\n";
			text << BuyersTeam1.tra[i].cardnumber << "\n";
			text << BuyersTeam1.tra[i].purchasecode << "\n";
		}
	}

	text.close();
	int i;
	int a;
	cout << "Enter purchase code:" << "\n";
	cin >> a;

	for (int j = 0; j < b; j++)
	{
		if (a == BuyersTeam1.tra[j].purchasecode)
		{
			cout << BuyersTeam1.tra[j].surname << "\n";
			cout << BuyersTeam1.tra[j].name << "\n";
			cout << BuyersTeam1.tra[j].patronymic << "\n";
			cout << BuyersTeam1.tra[j].city << "\n";
			cout << BuyersTeam1.tra[j].street << "\n";
			cout << BuyersTeam1.tra[j].housenumber << "\n";
			cout << BuyersTeam1.tra[j].flatnumber << "\n";
			cout << BuyersTeam1.tra[j].cardnumber << "\n";
			cout << BuyersTeam1.tra[j].purchasecode << "\n";
			break;
		}
	}
	getchar();
	getchar();
	int t = 1;

	while (t == 1) {
		t = 0;
		for (int f = 0; f < (b - 1); f++) {
			if (BuyersTeam1.tra[f].purchasecode < BuyersTeam1.tra[f + 1].purchasecode) {
				int temp_purchasecode = BuyersTeam1.tra[f].purchasecode;
				BuyersTeam1.tra[f].purchasecode = BuyersTeam1.tra[f + 1].purchasecode;
				BuyersTeam1.tra[f + 1].purchasecode = temp_purchasecode;

				int temp_name[50];
				for (i = 0; i < 50; i++) {
					char temp_bukva = BuyersTeam1.tra[f].name[i];
					BuyersTeam1.tra[f].name[i] = BuyersTeam1.tra[f + 1].name[i];
					BuyersTeam1.tra[f + 1].name[i] = temp_bukva;
				}

				t = 1;
			}
		}
	}

	for (int i = 0; i < b; i++) {
		cout << BuyersTeam1.tra[i].name;
		cout << "\t";
		cout << BuyersTeam1.tra[i].purchasecode << endl;

	}

	return 0;
}