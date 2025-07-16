#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n[5], num[14], pair[3],i;
	while (scanf("%d,%d,%d,%d,%d",&n[0],&n[1],&n[2],&n[3],&n[4]) != EOF){
		i = 0;
		for (int i = 0; i < 14; i++) num[i] = 0;
		for (int i = 0; i < 3; i++) pair[i] = 0;
		for (int i = 0; i < 5; i++) num[n[i] - 1]++;
		for (int i = 0; i < 13; i++){
			if (num[i] > 1) pair[num[i] - 2]++;
		}
		if (pair[2]) cout << "four card" << endl;
		else if (pair[0] && pair[1]) cout << "full house" << endl;
		else if (pair[1]) cout << "three card" << endl;
		else if (pair[0] == 2) cout << "two pair" << endl;
		else if (pair[0]) cout << "one pair" << endl;
		else{
			num[13] = num[0];
			for (i = 0; i < 10; i++){
				if (num[i] == 1 && num[i] == num[i + 1] && num[i + 1] == num[i + 2] && num[i + 2] == num[i + 3] && num[i + 3] == num[i + 4]) {
					cout << "straight" << endl;
					break;
				}
			}
		}
		if (i == 10)  cout << "null" << endl;
	}
	return 0;
}