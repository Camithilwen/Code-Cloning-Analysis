#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int straight(int[]);

int main() {

	int ans, h[5];

	while(scanf("%d,%d,%d,%d,%d", &h[0], &h[1], &h[2], &h[3], &h[4])!=EOF) {
		ans=0;
		for(int i=0; i<4; i++) {
			for(int j=i+1; j<5; j++) {
				if(h[i]==h[j])
					ans++;
			}
		}
		switch(ans) {
			case 1:
				cout << "one pair" << endl;
				break;
			case 2:
				cout << "two pair" << endl;
				break;
			case 3:
				cout << "three card" << endl;
				break;
			case 4:
				cout << "full house" << endl;
				break;
			case 6:
				cout << "four card" << endl;
				break;
			default:
				if(straight(h))
					cout << "straight" << endl;
				else
					cout << "null" << endl;
		}
	}
	
	return 0;

}

int straight(int h[5]) {
	
	sort(h, h+5);
	for(int i=0; i<9; i++) {
		if(h[0]==i&&h[1]==i+1&&h[2]==i+2&&h[3]==i+3&&h[4]==i+4||h[0]==1&&h[1]==10&&h[2]==11&&h[3]==12&&h[4]==13)
			return 1;
	}

	return 0;

}