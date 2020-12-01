#include <iostream>
using namespace std;
int mSt[6][7] = {
	{0,2,3,4,0,-1,6},
	{1,1,1,1,1,1,6},
	{-1,2,-1,-1,-1,-1,6},
	{-1,-1,-1,-1,-1,-1,6},
	{6,6,6,6,6,6,6},
	{0,0,0,0,0,0,6}
}; //массив состояния
int mD[6][7] = {
	{0,2,2,2,0,-1,7},
	{1,1,1,1,1,1,7},
	{-1,2,-1,-1,-1,-1,7},
	{-1,-1,-1,-1,-1,-1,7},
	{3,3,3,3,3,3,7},
	{0,0,0,0,0,0,7}
}; //массив действия
int st = 0;


int main()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << mSt[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << mD[i][j] << '\t';
		}
		cout << endl;
	}

	int hpg = 20; //здоровье героя
	float vg = 2.5; //скорость
	int rag = 3; //радиус атаки
	int dmg = 2; //урон
	float xg; //координата

	int hpm = 20; //здоровье монстра
	float vm = 2; //скорость
	float rom = 3; //радиус обнаружения героя
	float ram = 1; //радиус атаки (ram<=rom)
	int dmm = 5; //урон
	float xm; //координата

	int a = 0;
	float dist;
	int st = 0;
	int d;

	char act;

	cout << "x_hero = ";
	cin >> xg;
	cout << "x_monster = ";
	cin >> xm;

	while (a != 4 && a != 5)
	{
		cout << "Enter command (l-left, r-right, s-stand, a-attack): ";
		cin >> act;
		switch (act)
		{
			case 'l': xg -= vg; break; //Указание герою идти влево
			case 'r': xg += vg; break; //Вправо
			case 's': break; //Стоять на месте
			case 'a': //Атаковать
			{
				dist = xg - xm;
				dist = dist > 0 ? dist : -dist;
				if (dist <= rag)hpm -= dmg;
				break;
			}
			default: break;
		}

		dist = xg - xm;
		dist = dist > 0 ? dist : -dist;
		cout << "Stats before this round:" << endl;
		cout << "Distance = " << dist << endl;
		cout << "xm = " << xm << endl;
		cout << "xg = " << xg << endl;
		cout << "hpm = " << hpm << endl;
		cout << "hpg = " << hpg << endl;

		if (hpg <= 0) a = 5;
		if (hpm <= 0) a = 4;
		if (hpg > 0 && hpm > 0 && dist > rom) a = 0;
		if (hpg > 0 && hpm > 0 && dist <= rom && dist > ram) a = 1;
		if (hpg > 0 && hpm > 0 && dist <= rom && dist <= ram) a = 2;


		d = mD[a][st];
		st = mSt[a][st];
		cout << "Stats after this round:" << endl;
		switch (d)
		{
			case 0:	cout << "Respond: random move" << endl; break;
			case 1:
			{
				if (xm > xg) xm -= vm;
				else xm += vm;
				cout << "Respond: monster follows" << endl; break;
			}
			case 2:
			{
				hpg -= dmm;
				cout << "Respond: monster attacks" << endl; break;
			}
			case 3: cout << "Monster is dead" << endl; break;
			default: break;
		}
		
		cout << "xm = " << xm << endl;
		cout << "xg = " << xg << endl;
		cout << "hpm = " << hpm << endl;
		cout << "hpg = " << hpg << endl<<endl;
	}

	return 0;
}

