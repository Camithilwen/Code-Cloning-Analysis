#include<iostream>
#include<string>
using namespace std;

int Roman_to_Arabia(char c){
	if (c == 'I')return 1;
	else if (c == 'V')return 5;
	else if (c == 'X')return 10;
	else if (c == 'L')return 50;
	else if (c == 'C')return 100;
	else if (c == 'D')return 500;
	else if (c == 'M')return 1000;
	else return 0;
}

int main(){
	string roman;
	int num;

	while (cin >> roman){
		num = 0;

		for (int i = 0; i < roman.size(); ++i){

			if (Roman_to_Arabia(roman[i]) < Roman_to_Arabia(roman[i + 1]))
				num -= Roman_to_Arabia(roman[i]);
			else
				num += Roman_to_Arabia(roman[i]);			
		}
		cout << num << endl;
	}
	return 0;
}