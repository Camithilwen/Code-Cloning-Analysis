#include <iostream>

using namespace std;

int main(){
	int x;
	cin >> x;
	int pleasure = 0;
	int f = x / 500;
	x -= f * 500;
	pleasure += 1000 * f;
	
	f = x / 5;
	x -= f * 5;
	pleasure += 5 * f;
	
	cout << pleasure << endl;
}