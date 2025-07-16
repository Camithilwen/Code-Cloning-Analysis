#include<iostream>
#include<string>
using namespace std;

class Base {
public:
	Base() {
		score = 0;
		outNum = 0;
		first = false;
		second = false;
		third = false;
	}
	void hit() {
		if (third) {
			score++;
		}
		third = second;
		second = first;
		first = true;
	}
	void homerun() {
		if (first) {
			first = false;
			score++;
		}
		if (second) {
			second = false;
			score++;
		}
		if (third) {
			third = false;
			score++;
		}
		score++;
	}
	void out() {
		outNum++;
		if (outNum > 2) {
			cout << score << endl;
			score = 0;
			outNum = 0;
			first = false;
			second = false;
			third = false;
		}
	}
	
private:
	int score;
	int outNum;
	bool first;
	bool second;
	bool third;
};


int main() {
	Base base;
	string str;
	int inning;
	int count = 0;

	cin >> inning;

	while (count < inning * 3) {
		char data[10];
		cin >> str;
		if (str == "HIT") {
			base.hit();
		}else if (str == "HOMERUN") {
			base.homerun();
		}
		else if(str == "OUT"){
			base.out();
			count++;
		}
	}
	return 0;
}