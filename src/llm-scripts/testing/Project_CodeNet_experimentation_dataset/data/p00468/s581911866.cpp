#include <iostream>
#include <fstream>
using namespace std;

int main() {

	//ifstream cin("INPUT.txt");
	//ofstream cout("OUTPUT.txt");

	int n, m, sum, i;
	int a, b;

	while(cin >> n >> m, n != 0 && m != 0) {

	int friends[500] = {0}; //1=友達 2=友達の友達
	int m1[10000] = {0};
	int m2[10000] = {0};
	for(i = 0; i < m; i++) {
		cin >> m1[i] >> m2[i];
	}
	for(i = 0; i < m; i++) {
		a = m1[i];
		b = m2[i];
		if(friends[a-1] == 1 && friends[b-1] == 1) {
		} else if(a == 1) {
			friends[b-1] = 1;
		} else if(b == 1) {
			friends[a-1] = 1;
		} else if(friends[a-1] == 1) {
			friends[b-1] = 2;
		} else if(friends[b-1] == 1) {
			friends[a-1] = 2;
		}
	}
	for(i = 0; i < m; i++) {
		a = m1[i];
		b = m2[i];
		if(friends[a-1] == 1 && friends[b-1] == 1) {
		} else if(a == 1) {
			friends[b-1] = 1;
		} else if(b == 1) {
			friends[a-1] = 1;
		} else if(friends[a-1] == 1) {
			friends[b-1] = 2;
		} else if(friends[b-1] == 1) {
			friends[a-1] = 2;
		}
	}
	sum = 0;
	for(i = 0; i < n; i++) {
		if(friends[i] > 0)
			sum++;
	}

	cout << sum << endl;

	}

	return 0;

}