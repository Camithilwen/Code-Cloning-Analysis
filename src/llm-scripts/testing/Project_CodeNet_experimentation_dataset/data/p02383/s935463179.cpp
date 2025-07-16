#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int siz[6], damy;
	char mozi[2];
	for (int abc = 0; abc < 6; abc++) {
		cin >> siz[abc];
	}
	fgets(mozi,2,stdin);
	while(true){
		fgets(mozi,2,stdin);
		if (mozi[0] == '\n') {
			cout << siz[0] << endl;
			break;
		}
		switch (mozi[0]) {
		case 'S':
			damy = siz[0];
			siz[0] = siz[4];
			siz[4] = siz[5];
			siz[5] = siz[1];
			siz[1] = damy;
			break;
		case 'E':
			damy = siz[0];
			siz[0] = siz[3];
			siz[3] = siz[5];
			siz[5] = siz[2];
			siz[2] = damy;
			break;
		case 'N':
			damy = siz[0];
			siz[0] = siz[1];
			siz[1] = siz[5];
			siz[5] = siz[4];
			siz[4] = damy;
			break;
		case 'W':
			damy = siz[0];
			siz[0] = siz[2];
			siz[2] = siz[5];
			siz[5] = siz[3];
			siz[3] = damy;
			break;
		}
	}
	return 0;
}