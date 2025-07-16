#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int n;
	int kaisu;
	int team[100][3] = {0};
	int teamn[100];
	int a,b,c,d;
	int kari;
	int juni = 1;
	int counter = 1;
	
	cin >> n;
	kaisu = n * (n - 1) / 2;

	for (int i = 0; i < n; i++) {
		team[i][0] = i;
	}

	for (int i = 0; i < kaisu; i++) {
		cin >> a >> b >> c >> d;
		if (c > d) {
			team[a-1][1] += 3;
		} else if ( c < d) {
			team[b-1][1] += 3;
		} else {
			team[a-1][1] += 1;
			team[b-1][1] += 1;
		}
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (team[j][1] < team[j+1][1]) {
				for (int k = 0; k < 2; k++) {
					kari = team[j][k];
					team[j][k] = team[j+1][k];
					team[j+1][k] = kari;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		team[i][2] = juni;
		if (team[i][1] > team[i+1][1]) {
			juni += counter;
			counter = 1;
		} else {
			counter++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (team[j][0] == i) {
				cout << team[j][2] << endl;
				break;
			}
		}
	}
	return 0;
}