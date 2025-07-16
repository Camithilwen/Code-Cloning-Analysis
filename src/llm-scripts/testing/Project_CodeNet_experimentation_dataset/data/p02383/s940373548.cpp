#include <iostream>
#include <string>
using namespace std;

class Dice{
	int top, n, s, e, w;
public:
	Dice();
	void roll(char dir);
	int getTop();
};

Dice::Dice(){
	top = 1;
	n = 5;
	s = 2;
	e = 3;
	w = 4;
}

void Dice::roll(char dir){
	switch (dir){
	case 'N':
		n = top;
		top = s;
		s = 7 - n;
		break;
	case 'S':
		s = top;
		top = n;
		n = 7 - s;
		break;
	case 'E':
		e = top;
		top = w;
		w = 7 - e;
		break;
	case 'W':
		w = top;
		top = e;
		e = 7 - w;
		break;
	}
}

int Dice::getTop(){
	return top;
}

int main(void){
	int num[6];
	string str;
	Dice dice;

	for (int i = 0; i < 6; i++){
		cin >> num[i];
	}

	cin >> str;

	for (int i = 0; i < str.size(); i++){
		dice.roll(str[i]);
	}
	
	cout << num[dice.getTop()-1] << "\n";

	return 0;
}