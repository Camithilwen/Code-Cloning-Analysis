#include<iostream>
using namespace std;

int x, i = 1;
int n;

void check_num();
void include3();
void end_check_num();

void check_num() {
	x = i;
	if (x % 3 == 0){
		cout << " " << i;
		end_check_num();
	}else include3();
}

void include3() {
	if (x % 10 == 3){
		cout << " " << i;
		end_check_num();
	}else{
		x /= 10;
		if (x)include3();
		else end_check_num();
	}
}

void end_check_num() {
	if (++i <= n) check_num();
}


int main() {
	cin >> n;
	check_num();
	cout << endl;
	char c;
	cin >> c;
}