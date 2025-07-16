#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main(){
	int hand[5];
	char s[4];
	while(cin >> hand[0] >> s[0] >> hand[1] >> s[1] >> hand[2] >> s[2] >> hand[3] >> s[3] >> hand[4]){
		int trump[14] = {};
		for(int i = 0; i < 5; i++)trump[hand[i]]++;
		for(int i = 1; i <= 10; i++){
			for(int j = 0; j < 5; j++){
				int k = i + j;
				if(k == 14)k = 1;
				if(trump[k] != 1)goto no;
			}
			cout << "straight" << endl;
			goto fin;
			no:;
		}
		sort(trump, trump + 14, greater<int>());
		if(trump[0] == 4){
			cout << "four card" << endl;
			goto fin;
		}else if(trump[0] == 3 && trump[1] == 2){
			cout << "full house" << endl;
			goto fin;
		}else if(trump[0] == 3){
			cout << "three card" << endl;
			goto fin;
		}else if(trump[0] == 2 && trump[1] == 2){
			cout << "two pair" << endl;
			goto fin;
		}else if(trump[0] == 2){
			cout << "one pair" << endl;
			goto fin;
		}
		cout << "null" << endl;
		fin:;
	}
}
