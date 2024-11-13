#include <bits/stdc++.h>
#include "deck.h"

using namespace std;

struct Player
{
	string name;
	vector<Card> c;
	int money, tot;
} wo, ni;

int main()
{
	system("color 0f");
	printf("--------- Black Jack ---------\n\n");
	
	Deck dick;
	
	printf("Game for 2, type your names:\n\n");
	cin >> wo.name >> ni.name;
	mt19937 rnd(time(0));
	if (rnd() & 1)
		swap(wo, ni);
	printf("\n\n    ");
	cout << wo.name << " is ^DAD^.";
	printf("\n    ");
	cout << ni.name << " is _son_.\n\n------------------------------\n\n";
	system("pause");
	wo.money = ni.money = 800;
	wo.money += (rnd() % 30) * 10;
	int tott = 0;
	system("color 03");
	
	while (wo.money > 0 && ni.money > 0)
	{
		system("cls");
		printf("---------- Round %2d ----------\n\n", ++tott);
		wo.c.clear(), ni.c.clear();
		
		cout << "^DAD^ = " << wo.money << "    " << wo.name << endl;
		cout << "_son_ = " << ni.money << "    " << ni.name << "\n\n\n";
		
		cout << "_son_ " << ni.name << ", how many will you bet?\n";
		int a[4] = {ni.money / 10, ni.money / 4, ni.money / 2, ni.money};
		printf("    Choose from: %d | %d | %d | %d --- ", a[0], a[1], a[2], a[3]);
		int a1;
		cin >> a1;
		while (a1 != a[0] && a1 != a[1] && a1 != a[2] && a1 != a[3])
		{
			printf("\n    Fuck you! Choose from: %d | %d | %d | %d --- ", a[0], a[1], a[2], a[3]);
			cin >> a1;
		}
		cout << "\n       _son_ -= " << a1 << endl;
		ni.money -= a1;
		cout << "       ^DAD^ -= " << a1 << endl
		<< endl;
		wo.money -= a1;
		system("pause");
		
		system("cls");
		printf("---------- Game running ----------\n\n");
		
		cout << "^DAD^ = " << wo.money << "    " << wo.name << endl;
		cout << "_son_ = " << ni.money << "    " << ni.name << "\n\n\n";
		
		dick.init();
		dick.shuffle(time(0));
		wo.c.push_back(dick.deal());
		if (wo.c.back().getPoint() > 10)
			wo.c.pop_back(), wo.c.push_back({10, 0});
		wo.c.push_back(dick.deal());
		if (wo.c.back().getPoint() > 10)
			wo.c.pop_back(), wo.c.push_back({10, 0});
		ni.c.push_back(dick.deal());
		if (ni.c.back().getPoint() > 10)
			ni.c.pop_back(), ni.c.push_back({10, 0});
		ni.c.push_back(dick.deal());
		if (ni.c.back().getPoint() > 10)
			ni.c.pop_back(), ni.c.push_back({10, 0});
		ni.tot = wo.tot = 0;
		
		cout << " Hey _son_ " << ni.name << ", you've got:\n\n";
		for (auto x : ni.c)
			cout << " | " << x.getPoint(), ni.tot += x.getPoint();
		cout << " |      total : " << ni.tot << "     ";
		system("pause");
		cout << "\n\n Hey ^DAD^ " << wo.name << ", you've got:\n\n";
		cout << " | " << wo.c[0].getPoint() << " |     ";
		wo.tot += wo.c[0].getPoint();
		
		auto chk = [=]()
		{
			if (ni.tot > 21)
			{
				cout << "\n\n     _son_, you bomb!" << "\n------------------\n";
				cout << "_son_ -= " << a1 / 2 << endl;
				ni.money -= a1 / 2;
				cout << "^DAD^ += " << a1 * 2 << endl;
				wo.money += a1 * 2;
			}
			if (wo.tot > 21)
			{
				cout << "\n\n     ^DAD^, you bomb!" << "\n------------------\n";
				cout << "^DAD^ -= " << a1 / 2 << endl;
				wo.money -= a1 / 2;
				cout << "_son_ += " << a1 * 2 << endl;
				ni.money += a1 * 2;
			}
			else if (ni.tot == wo.tot)
			{
				cout << "OK... You are the same." << "\n------------------\n";
				cout << "_son_ += " << a1 / 2 << endl;
				cout << "^DAD^ += " << a1 / 2 << endl;
				wo.money += a1 / 2;
				ni.money += a1 / 2;
			}
			else if (ni.tot < wo.tot)
			{
				cout << "\n\n ^DAD^ " << wo.name << " is closer to 21 ~" << "\n------------------\n";
				cout << "^DAD^ += " << a1 * 2 << endl;
				wo.money += a1 * 2;
			}
			else
			{
				cout << "\n\n _son_ " << ni.name << " is closer to 21 ~" << "\n------------------\n";
				cout << "_son_ += " << a1 * 2 << endl;
				ni.money += a1 * 2;
			}
		};
		
		cout << "\n\n My _son_ " << ni.name << ", take(1) or see(0)? -- ";
		int x;
		cin >> x;
		cout << endl;
		while (x)
		{
			ni.c.push_back(dick.deal());
			if (ni.c.back().getPoint() > 10)
				ni.c.pop_back(), ni.c.push_back({10, 0});
			ni.tot += ni.c.back().getPoint();
			for (auto x : ni.c)
				cout << " | " << x.getPoint();
			cout << " |\nYour total : " << ni.tot << " !      ";
			if (ni.tot > 21)
				break;
			cout << "\n\n Then, " << ni.name << ", take(1) or see(0)? -- ";
			cin >> x;
		}
		if (ni.tot > 21)
		{
			cout << "\n\n WoW, " << ni.name << ", you bomb!" << "\n------------------\n";
			cout << "_son_ -= " << a1 / 2 << endl;
			ni.money -= a1 / 2;
			cout << "^DAD^ += " << a1 * 2 << endl;
			wo.money += a1 * 2;
			system("pause");
			continue;
		}
		
		system("pause");
		
		cout << "\n For ^DAD^ ...\n";
		for (auto x : wo.c)
			cout << " | " << x.getPoint();
		wo.tot += wo.c[1].getPoint();
		cout << " |      total : " << wo.tot << "  ";
		while (wo.tot < 18)
		{
			cout << "\n\n Less than 19, " << wo.name << ", take(1) or stop(0)? -- ";
			int x;
			cin >> x;
			cout << endl;
			if (x)
			{
				wo.c.push_back(dick.deal());
				if (wo.c.back().getPoint() > 10)
					wo.c.pop_back(), wo.c.push_back({10, 0});
				wo.tot += wo.c.back().getPoint();
				for (auto x : wo.c)
					cout << " | " << x.getPoint();
				cout << " |\nYour total : " << wo.tot << " !      ";
			}
			else
				break;
		}
		chk();
		system("pause");
	}
	
	system("cls");
	system("color 06");
	printf("---------- Game Over! ----------\n\n");
	
	cout << "^DAD^ = " << wo.money << "    " << wo.name << endl;
	cout << "_son_ = " << ni.money << "    " << ni.name << "\n\n\n";
	
	if (wo.money <= 0)
		cout << "----" << wo.name << " committed suicide with " << wo.money << "...\n----Congratulate to " << ni.name << "!!!\n\n";

	if (ni.money <= 0)
		cout << "----" << ni.name << " committed suicide with " << ni.money << "...\n----Congratulate to " << wo.name << "!!!\n\n";

	system("pause");
	
	return 0;
}
