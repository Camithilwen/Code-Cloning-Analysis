#include<iostream>
#include<string.h>

using namespace std;

int main(){
//	int input = 0;
	char input[10];
	cin >> input;
//	int angka1 = input%10;
//	int angka2 = input-100-angka1;
//	angka2 = angka2/10;
//	int angka3 = input-angka2-angka1;
//	angka3 = angka3/100;
	if(input[0] == '7' || input[1] == '7' || input[2] == '7'){
		cout << "Yes" <<endl;
		}
	else {
		cout << "No" << endl;
	}
	return 0;
}
