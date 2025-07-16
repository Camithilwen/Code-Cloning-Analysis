#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	int card[4];
	char c;

	while(cin >> card[0] ){
		for(int i=1;i<5;i++){
			cin >> c >> card[i];
		}
		sort(card, card+5);

		int two = 0;
		bool three = 0;
		bool four = 0;

		for(int i=0;i<5;i++){
			int count = 1;
			for(int j=i+1;j<5;j++){
				if(card[i]==card[j]){
					count++;
				}
				else{
					break;
				}
			}
			if(count==2){
				two+=1;
				i+=1;
			}
			else if(count==3){
				three=1;
				i+=2;
			}
			else if(count==4){
				four=1;
				i+=3;
			}
		}

		if(two && three){
			cout << "full house" << endl;
		}else if(two==2){
			cout << "two pair" <<endl;
		}else if(two==1){
			cout << "one pair" <<endl;
		}else if(three){
			cout << "three card" <<endl;
		}else if(four){
			cout << "four card" <<endl;
		}else{
			bool straight_flag = 1;
			bool ace_flag = 1;
			bool has_13 = 0;
			if(card[4]==13){
				has_13=1;
			}

			for(int i=3;i>=0;i--){
				if(ace_flag && card[i+1]-1==card[i]){
					//cout<<1;
				}else if(ace_flag && has_13 && card[i]==i+1){
					//cout<<0;
					ace_flag=0;
				}else{
					straight_flag=0;
					break;
				}
			}

			if(straight_flag){
				cout << "straight" << endl;
			}else{
				cout << "null" << endl;
			}
		}
	}
	return 0;
}