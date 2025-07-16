#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>

const int coin[6] = { 500,100,50,10,5,1 };

using namespace std;

struct Expm { int a, b, c, r; };

int main(){
	
	/*int answer[5][2] = { 0 };
	int n = 0;

	int buf[100];
	int ndataset;
	for (ndataset = 0; ; ndataset++) {

		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> buf[i];
		}

		sort(&buf[0], &buf[n]);

		int scoreT = 0;
		int scoreH = 0;
		for (int i = 0; i < n; i++) {
			int sbase = 2 * i + 1 - buf[i];
			if (sbase > 0) {
				scoreH = max(abs(sbase), scoreH);
			}
			else {
				scoreT = max(abs(sbase), scoreT);
			}
		}
		if (scoreH > scoreT) scoreT = 0;
		if (scoreH <= scoreT) scoreH = 0;
		answer[ndataset][0] = scoreT;
		answer[ndataset][1] = scoreH;

	} // dataset

	for (int i = 0; i < ndataset; i++) {
		cout << answer[i][0] << endl;
		cout << answer[i][1] << endl;
	}*/

	int resA[5][100]; int resB[5][100]; int resC[5][100];
	int numa[5], numb[5], numc[5], nume[5];
	int set = 0;

	for (;; set++) {

		Expm expm[1000];

		cin >> numa[set] >> numb[set] >> numc[set];
		if (numa[set] == 0 && numb[set] == 0 && numc[set] == 0) break;

		for (int i = 0; i < numa[set]; i++) resA[set][i] = 2;
		for (int i = 0; i < numb[set]; i++) resB[set][i] = 2;
		for (int i = 0; i < numc[set]; i++) resC[set][i] = 2;

		cin >> nume[set];
		for (int i = 0; i < nume[set]; i++) {
			cin >> expm[i].a
				>> expm[i].b
				>> expm[i].c
				>> expm[i].r;
			if (expm[i].r) {
				resA[set][expm[i].a-1] = resB[set][expm[i].b-numa[set]-1] =
					resC[set][expm[i].c - numa[set] - numb[set] -1] = 1;
			}
		}
		for (int i = 0; i < nume[set]; i++) {
			if (expm[i].r) continue;
			if (resA[set][expm[i].a-1] == 1 &&
				resB[set][expm[i].b - numa[set] -1] == 1)
				resC[set][expm[i].c - numa[set] - numb[set] -1] = 0;
			if (resC[set][expm[i].c - numa[set] - numb[set] -1] == 1 &&
				resB[set][expm[i].b - numa[set] -1] == 1)
				resA[set][expm[i].a-1] = 0;
			if (resA[set][expm[i].a-1] == 1 &&
				resC[set][expm[i].c - numa[set] - numb[set] -1] == 1)
				resB[set][expm[i].b - numa[set] -1] = 0;
		}
	}

	for (int j = 0; j < set; j++) {
		for (int i = 0; i < numa[j]; i++)
			cout << resA[j][i] << endl;
		for (int i = 0; i < numb[j]; i++)
			cout << resB[j][i] << endl;
		for (int i = 0; i < numc[j]; i++)
			cout << resC[j][i] << endl;
	}

	return 0;
}
