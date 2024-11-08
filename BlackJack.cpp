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
	system("color 03");
	printf("--------- Black Jack ---------\n\n");
	
	Deck dick;
	
	printf("Game for 2, type your names:\n\n");
	cin >> wo.name >> ni.name;
	mt19937 rnd(time(0));
	if (rnd() & 1)
		swap(wo, ni);
	printf("\n\n    ");
	cout << wo.name << " is Dad.";
	printf("\n    ");
	cout << ni.name << " is Son.\n\n------------------------------\n\n";
	system("pause");
	wo.money = ni.money = 800;
	int tott = 0;
	while (wo.money > 0 && ni.money > 0)
	{
		system("cls");
		printf("---------- Round %2d ----------\n\n", ++tott);
		wo.c.clear(), ni.c.clear();
		
		cout << "Dad = " << wo.money << "    " << wo.name << endl;
		cout << "Son = " << ni.money << "    " << ni.name << "\n\n\n";
		
		cout << "Son " << ni.name << ", how many will you bet?\n";
		int a[4] = {ni.money / 10, ni.money / 4, ni.money / 2, ni.money};
		printf("    Choose from: %d | %d | %d | %d --- ", a[0], a[1], a[2], a[3]);
		int a1;
		cin >> a1;
		while (a1 != a[0] && a1 != a[1] && a1 != a[2] && a1 != a[3])
		{
			printf("\n    Fuck you! Choose from: %d | %d | %d | %d --- ", a[0], a[1], a[2], a[3]);
			cin >> a1;
		}
		cout << "\n       Son -= " << a1 << endl;
		ni.money -= a1;
		cout << "\nDad " << wo.name << ", then how many will you bet?\n";
		int b[4] = {wo.money / 10, wo.money / 4, wo.money / 2, wo.money};
		printf("    Choose from: %d | %d | %d | %d --- ", b[0], b[1], b[2], b[3]);
		int a0;
		cin >> a0;
		while (a0 != b[0] && a0 != b[1] && a0 != b[2] && a0 != b[3])
		{
			printf("\n    Fuck you! Choose from: %d | %d | %d | %d --- ", b[0], b[1], b[2], b[3]);
			cin >> a0;
		}
		cout << "\n       Dad -= " << a0 << endl;
		wo.money -= a0;
		system("pause");
		
		system("cls");
		printf("---------- Game running ----------\n\n");
		
		cout << "Dad = " << wo.money << "    " << wo.name << endl;
		cout << "Son = " << ni.money << "    " << ni.name << "\n\n\n";
		
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
		
		cout << " Hey son " << ni.name << ", you've got:\n\n";
		for (auto x : ni.c)
			cout << " | " << x.getPoint(), ni.tot += x.getPoint();
		cout << " |      total : " << ni.tot << "     ";
		system("pause");
		cout << "\n\n Hey dad " << wo.name << ", you've got:\n\n";
		cout << " | " << wo.c[0].getPoint() << " |     ";
		wo.tot += wo.c[0].getPoint();
		
		auto chk = [=]()
		{
			if (ni.tot > 21)
			{
				cout << "\n\n Son, you bomb!" << "\n------------------\n";
				cout << "Son -= " << a1 << endl;
				cout << "Dad += " << a0 + a1 << endl;
				ni.money -= a1;
				wo.money += a0 + a1;
			}
			if (wo.tot > 21)
			{
				cout << "\n\n Dad, you bomb!" << "\n------------------\n";
				cout << "Dad -= " << a0 << endl;
				cout << "Son += " << a0 + a1 << endl;
				wo.money -= a0;
				ni.money += a0 + a1;
			}
			else if (ni.tot == wo.tot)
			{
				cout << "OK... You are the same." << "\n------------------\n";
			}
			else if (ni.tot < wo.tot)
			{
				cout << "\n\n Dad " << wo.name << " is closer to 21 ~" << "\n------------------\n";
				cout << "Son -= " << a1 << endl;
				cout << "Dad += " << a0 + a1 << endl;
				ni.money -= a1;
				wo.money += a0 + a1;
			}
			else
			{
				cout << "\n\n Son " << ni.name << " is closer to 21 ~" << "\n------------------\n";
				cout << "Dad -= " << a0 << endl;
				cout << "Son += " << a0 + a1 << endl;
				wo.money -= a0;
				ni.money += a0 + a1;
			}
		};
		
		cout << "\n\n My Son " << ni.name << ", take(1) or see(0)? -- ";
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
			cout << "\n\n Haha, " << ni.name << ", you bomb!" << "\n------------------\n";
			cout << "Son -= " << a1 << endl;
			cout << "Dad += " << a0 + a1 << endl;
			ni.money -= a1;
			wo.money += a0 + a1;
			system("pause");
			continue;
		}
		
		system("pause");
		
		cout << "\n For dad ...\n";
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
	printf("---------- Game Over! ----------\n\n");
	
	cout << "Dad = " << wo.money << "    " << wo.name << endl;
	cout << "Son = " << ni.money << "    " << ni.name << "\n\n\n";
	
	if (wo.money <= 0)
		cout << "    " << wo.name << " sold his house, his wife, his son to bet, but went out with " << wo.money << "...\n Congratulate to " << ni.name << "!!!\n\n";
	if (ni.money <= 0)
		cout << "    " << ni.name << " sold his house, his wife, his son to bet, but went out with " << ni.money << "...\n    Congratulate to " << wo.name << "!!!\n\n";
	
	system("pause");
	
	return 0;
}

