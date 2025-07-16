#include<iostream>
#include<string>
using namespace std;

class DICE
{
private:
	const int dice_tem[5][6] = { { 3,2,6,1,5,4 },{ 2,6,3,4,1,5 },
	{ 5,1,3,4,6,2 },{ 4,2,1,6,5,3 },{1,2,3,4,5,6} }; //{0}:W {1}:N {2}:S {3}:E {4}:defalut   
	const string dice_rl = "AWWWNWWWNWWWWNWWWSWWWSWWW";
	const int n = 6;
	int dice_i[6] = { 0 };
	int dice_j[6] = { 0 };
	int a = 4;

	void setup() {
		for (int i = 0; i < n; i++) {
			cin >> dice[i];
			dice_i[i] = dice[i];
		}
	}

public:
	int dice[6];
	int num = 0;
	const int dice_suffle_num = dice_rl.length();
	DICE() {
	
	}
	void roll_dice() {
		switch (dice_rl[num])
		{
		case 78: //N
			a = 1;
			break;
		case 83: //S
			a = 2;
			break;
		case 87: //W
			a = 0;
			break;
		case 69: //E
			break;
			a = 3;
		default:
			a = 4;
			break;
		}

		for (int i = 0; i < n; i++) dice_j[i] = dice_i[dice_tem[a][i] - 1];
		for (int i = 0; i < n; i++) dice_i[i] = dice_j[i];
		num++;
		if (num > dice_suffle_num) num = 0;
	}
	int check(int i) {
		return dice_i[i];
	}
	void set()
	{
		setup();
	}
};

int main() {
	const int n = 6;
	bool flag = true;
	int num;
	cin >> num;
	const int con_num = num;
	DICE dice[100];
	for (int i = 0; i < num ; i++)dice[i].set();
	for (int i = 0; i < num - 1; i++) {
		for (int j = i+1; j < num; j++) {
			for (int k = 0; k < dice[0].dice_suffle_num;k++) {
				dice[j].roll_dice();
				for (int l = 0; l < n; l++) {
					if (dice[i].dice[l] != dice[j].check(l)) {
						flag = true;
						break;
					}
					flag = false;
				}
				if (flag == false)break;
			}
			if (flag == false)break;
		}
		if (flag == false)break;
	}

	if (flag == true) {
		cout << "Yes" << endl;
	}
	else if (flag == false) {
		cout << "No" << endl;
	}
	return 0;
}

