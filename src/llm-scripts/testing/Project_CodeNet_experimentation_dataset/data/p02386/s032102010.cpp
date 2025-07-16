#include <bits/stdc++.h> 

#define DICE_SIZE 6

#define TOP    0
#define FRONT  1
#define RIGHT  2
#define LEFT   3
#define BACK   4
#define BOTTOM 5

using namespace std;

class Dice {
	private:
		int number[DICE_SIZE];
		int work_space[DICE_SIZE];

		void reset_number(int, int, int, int, int, int);

	public:
		Dice(int *);
		void turn(char);
		void turn_horizon();
		int peek(int);
		void set_top(int);
		int get_position(int);
		bool equals(Dice *);
};

Dice::Dice(int *number) {
	for (int i = 0; i < DICE_SIZE; i++) this->number[i] = number[i];
}

void Dice::turn(char direction) {
	for (int i = 0; i < DICE_SIZE; i++) work_space[i] = number[i];

	switch (direction) {
		case 'N':
			reset_number(work_space[1], work_space[5], work_space[2], work_space[3], work_space[0], work_space[4]);
			break;			
		case 'E':
			reset_number(work_space[3], work_space[1], work_space[0], work_space[5], work_space[4], work_space[2]);
			break;
		case 'S':
			reset_number(work_space[4], work_space[0], work_space[2], work_space[3], work_space[5], work_space[1]);
			break;
		case 'W':
			reset_number(work_space[2], work_space[1], work_space[5], work_space[0], work_space[4], work_space[3]);
			break;
	}
}

void Dice::turn_horizon() {
	for (int i = 0; i < DICE_SIZE; i++) work_space[i] = number[i];

	reset_number(work_space[0], work_space[3], work_space[1], work_space[4], work_space[2], work_space[5]);
}

int Dice::peek(int position) {
	return number[position];
}

int Dice::get_position(int num) {
	for (int i = 0; i < DICE_SIZE; i++) {
		if (number[i] == num) return i;
	}
}

void Dice::reset_number(int num0, int num1, int num2, int num3, int num4, int num5) {
	number[0] = num0;
	number[1] = num1;
	number[2] = num2;
	number[3] = num3;
	number[4] = num4;
	number[5] = num5;
}

void Dice::set_top(int num) {
	int current_position = get_position(num);

	if (current_position == RIGHT || current_position == LEFT) {
		while (peek(TOP) != num) {
			turn('W');
		}
	} else {
		while (peek(TOP) != num) {
			turn('N');
		}
	}
}

bool Dice::equals(Dice *dice) {
	bool eql_flg = true;
	for (int i = 0; i < DICE_SIZE; i++) {
		if (peek(i) != dice->peek(i)) {
			eql_flg = false;
			break;
		}
	}

	return eql_flg;
}

bool check_all_pattern(Dice *dice1, Dice *dice2) {
	bool eql_flg = false;

	for (int i = 0; i < DICE_SIZE; i++) {
		dice1->set_top(dice1->peek(i));

		for (int j = 0; j < DICE_SIZE; j++) {
			dice2->set_top(dice2->peek(j));

			for (int k = 0; k < 4; k++) {
				if (dice1->equals(dice2)) {
					eql_flg = true;
					goto RETURN;
				}

				dice2->turn_horizon();
			}
		}
	}

	RETURN:
		return eql_flg;
}

int main() {
	int n;
	int number[DICE_SIZE];
	
	cin >> n;
	Dice *dices[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < DICE_SIZE; j++) cin >> number[j];

		dices[i] = new Dice(number);
	}

	bool is_along_flg = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (check_all_pattern(dices[i], dices[j])) {
				is_along_flg = false;
				goto END;
			}
		}
	}

	END:
		cout << (is_along_flg ? "Yes" : "No") << endl;

	return 0;
}

