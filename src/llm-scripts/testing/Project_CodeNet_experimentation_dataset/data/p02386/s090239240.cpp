#include<iostream>
using namespace std;

struct Directions
{
	int E[6] = { 2, 1, 5, 0, 4, 3 };
	int W[6] = { 3, 1, 0, 5, 4, 2 };
	int N[6] = { 4, 0, 2, 3, 5, 1 };
	int S[6] = { 1, 5, 2, 3, 0, 4 };
	int Rotate[6] = { 0, 2, 4, 1, 3, 5 };
};

class Dice
{
public:
	int num[6];
	void swap(int*);
	Directions dir_array;
	Dice();
	void roll(char);
	void show_num(int);
};

Dice::Dice()
{
	for (int i = 0; i < 6; i++)
		cin >> this->num[i];
}

void Dice::roll(char c)
{
	switch (c)
	{
	case 'E':
		this->swap(dir_array.E);
		break;
	case 'W':
		this->swap(dir_array.W);
		break;
	case 'N':
		this->swap(dir_array.N);
		break;
	case 'S':
		this->swap(dir_array.S);
		break;
	case 'R':
		this->swap(dir_array.Rotate);
		break;
	}
	return;
}

void Dice::swap(int *dir)
{
	int tmp[6];
	for (int i = 0; i < 6; i++)
		tmp[dir[i]] = num[i];
	for (int i = 0; i < 6; i++)
		num[i] = tmp[i];
	return;
}

void Dice::show_num(int i)
{
	cout << this->num[i] << endl;
	return;
}

int check(Dice dice1, Dice dice2)
{
	int tmpf, flag = 0;
	for (int i = 0; i < 4; i++) {
		tmpf = 1;
		for (int j = 0; j < 6; j++)
			if (dice1.num[j] != dice2.num[j])
			{
				tmpf = 0;
				break;
			}
		if (tmpf)
			flag = 1;
		dice2.roll('R');
	}
	return flag;
}
int dice_comp(Dice dice1, Dice dice2)
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		flag += check(dice1, dice2);
		dice2.roll('E');
	}
	dice2.roll('N');
	flag += check(dice1, dice2);
	dice2.roll('N');
	dice2.roll('N');
	flag += check(dice1, dice2);
	return flag;
}

int main()
{
	int flag = 0, n;
	cin >> n;
	Dice dice1;
	for (int i = 1; i < n; i++)
	{
		Dice dice2;
		flag += dice_comp(dice1, dice2);
	}
	if (!flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
