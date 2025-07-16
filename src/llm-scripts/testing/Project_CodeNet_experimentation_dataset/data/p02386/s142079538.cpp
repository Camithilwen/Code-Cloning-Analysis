#include<iostream>

using namespace std;


class DICE {
	enum {
		Top,
		Front,
		Right,
		Left,
		Rear,
		Bottom
	};

	void Roll(const char*Directions) {
		for (int i = 0; Directions[i] != '\0'; i++) {
			Roll(Directions[i]);
		}
	}

	void Roll(const char Direction) {
		int tmpTop = Num[Top];

		switch (Direction) {
		case'E':
			Num[Top] = Num[Left];
			Num[Left] = Num[Bottom];
			Num[Bottom] = Num[Right];
			Num[Right] = Num[tmpTop];
			break;
		case'N':
			Num[Top] = Num[Front];
			Num[Front] = Num[Bottom];
			Num[Bottom] = Num[Rear];
			Num[Rear] = tmpTop;
			break;
		case'S':
			Num[Top] = Num[Rear];
			Num[Rear] = Num[Bottom];
			Num[Bottom] = Num[Front];
			Num[Front] = tmpTop;
			break;
		case'W':
			Num[Top] = Num[Right];
			Num[Right] = Num[Bottom];
			Num[Bottom] = Num[Left];
			Num[Left] = tmpTop;
			break;
		}
	}

	bool SameDiceDirectionFlag(DICE Dice) {
		for (int i = 0; i < 6; i++) {
			if (Num[i] != Dice.Num[i])return false;
		}
		return true;
	}

public:
	int Num[6];

	bool SameDiceNoneDirectionFlag(DICE Dice) {
		const char Directions[][3] = { "N","N","N","NW","WW","\0" };

		for (int i = 0; i < 6; i++) {
			if (Num[Top] == Dice.Num[Top]) {
				for (int j = 0; j < 4; j++) {
					if (SameDiceDirectionFlag(Dice))return true;

					int tmpFront = Dice.Num[Front];
					Dice.Num[Front] = Dice.Num[Right];
					Dice.Num[Right] = Dice.Num[Rear];
					Dice.Num[Rear] = Dice.Num[Left];
					Dice.Num[Left] = tmpFront;
				}
			}

			Dice.Roll(Directions[i]);
		}

		return false;
	}

};

int main() {
	DICE Dice[101];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++)cin >> Dice[i].Num[j];
	}

	for (int i = 1; i < n; i++) {
		if (Dice[0].SameDiceNoneDirectionFlag(Dice[i])) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}