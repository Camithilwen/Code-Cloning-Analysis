#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int c[5];
	while (scanf("%d,%d,%d,%d,%d", &c[0], &c[1], &c[2], &c[3], &c[4]) != EOF) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j<4; j++) {
				if (c[j] > c[j + 1]) {
					int tmp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = tmp;
				}
			}
		}
		if ((c[0]==c[1]&&c[1]==c[2]&&c[2]==c[3])||(c[1]==c[2]&&c[2]==c[3]&&c[3]==c[4]))cout << "four card" << endl;
		else if ((c[0]==c[1]&&c[1]==c[2]&&c[3]==c[4])||(c[0]==c[1]&&c[2]==c[3]&&c[3]==c[4]))cout << "full house" << endl;
		else if ((c[0]==1&&c[1]==10&&c[2]==11&&c[3]==12&&c[4]==13)||(c[0]+1==c[1]&&c[0]+2==c[2]&&c[0]+3==c[3]&&c[0]+4==c[4]))cout << "straight" << endl;
		else if ((c[0]==c[1]&&c[1]==c[2])||(c[1]==c[2]&&c[2]==c[3])||(c[2]==c[3]&&c[3]==c[4]))cout << "three card" << endl;
		else if ((c[0]==c[1]&&c[2]==c[3])||(c[1]==c[2]&&c[3]==c[4])||(c[0]==c[1]&&c[3]==c[4]))cout << "two pair" << endl;
		else if ((c[0] == c[1]) || (c[1] == c[2]) || (c[2] == c[3]) || (c[3] == c[4]))cout << "one pair" << endl;
		else cout << "null" << endl;
	}
}
