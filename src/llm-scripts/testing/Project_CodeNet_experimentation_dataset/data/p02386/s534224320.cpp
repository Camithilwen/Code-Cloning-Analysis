#include <iostream>

using namespace std;

class Dice {
private:
	int number[6];
	int state[6];
public:
	Dice();
	~Dice();
	void initialize();
	void setNumber(int index, int num);
	void roll(char d);
	void move(string d);
	int getNumber(int idx);
	int getTop();
	int getSide(int t, int f);
	bool cmp(Dice dice1);
};

Dice::Dice() {
	initialize();
}

Dice::~Dice() {
}

void Dice::initialize() {
	for (int i = 0; i < 6; i++)
		state[i] = i+1;
}

void Dice::setNumber(int index, int num) {
	number[index] = num;
}

void Dice::roll(char d) {
	int nextIndex[4][6] = {
		{1, 5, 2, 3, 0, 4},
		{3, 1, 0, 5, 4, 2},
		{2, 1, 5, 0, 4, 3},
		{4, 0, 2, 3, 5, 1},
	};
	int *idx, nextState[6];
	switch (d) {
		case 'N': idx = nextIndex[0]; break;
		case 'E': idx = nextIndex[1]; break;
		case 'W': idx = nextIndex[2]; break;
		case 'S': idx = nextIndex[3]; break;
		default: return;
	}
	for (int i = 0; i < 6; i++)
		nextState[i] = state[idx[i]];
	for (int i = 0; i < 6; i++)
		state[i] = nextState[i];
}

void Dice::move(string d) {
	int oldIndex[4][6] = {
		{1, 5, 2, 3, 0, 4},
		{3, 1, 0, 5, 4, 2},
		{2, 1, 5, 0, 4, 3},
		{4, 0, 2, 3, 5, 1},
	};
	for (int i = 0; i < d.size(); i++) {
		int newNumber[6] = {0};
		int *idx;
		char c = d[i];
		switch (c) {
			case 'N': idx = oldIndex[0]; break;
			case 'E': idx = oldIndex[1]; break;
			case 'W': idx = oldIndex[2]; break;
			case 'S': idx = oldIndex[3]; break;
			default: return;
		}
		for (int i = 0; i < 6; i++)
			newNumber[i] = number[idx[i]];
		for (int i = 0; i < 6; i++)
			number[i] = newNumber[i];
	}
}

int Dice::getNumber(int idx) {
	return number[state[idx]-1];
}

int Dice::getTop() {
	return getNumber(0);
}

int Dice::getSide(int t, int f) {
	string s = "NNNNENNNN";
	for (int i = 0; i < s.size(); i++) {
		if (number[state[1]-1] == f) {
			break;
		}
		char c = s[i];
		roll(c);
	}
	s = "EEEEE";
	for (int i = 0; i < s.size(); i++) {
		if (number[state[0]-1] == t)
			break;
		char c = s[i];
		roll(c);
	}
	return getNumber(2);
}

bool Dice::cmp(Dice op) {
	string s = "SWWWWNEEEEENEEEENNEEEESEEEEESEEEE";
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		op.roll(c);
		int flag = 0;
		for (int i = 0; i < 6; i++)
			if (op.getNumber(i) != number[i]) {
				flag = 1;
				break;
			}
		if (flag == 0)
			return true;
	}
	return false;
}

int main() {
	Dice *dice;
	int n, m;
	cin >> n;
	dice = new Dice[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> m;
			dice[i].setNumber(j, m);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dice[i].cmp(dice[j]) == true) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}