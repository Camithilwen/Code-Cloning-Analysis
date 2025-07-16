#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>

typedef long long ll;
using namespace std;

bool is_1pair(int* cards){
	sort(cards,cards+5);
	map<int,int> freq;
	for(int i=0;i<5;i++){
		freq[cards[i]]++;
	}
	
	int count = 0;
	for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second == 2){
			count++;
		}
		if(it->second == 3){
			return false;
		}
	}

	return count == 1;
}

bool is_2pair(int* cards){
	sort(cards,cards+5);
	map<int,int> freq;
	for(int i=0;i<5;i++){
		freq[cards[i]]++;
	}
	
	int count = 0;
	for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second == 2){
			count++;
		}
	}

	return count == 2;
}

bool is_3card(int* cards){
	sort(cards,cards+5);
	map<int,int> freq;
	for(int i=0;i<5;i++){
		freq[cards[i]]++;
	}
	
	int count = 0;
	for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second == 3){
			count++;
		}
		if(it->second == 2){
			return false;
		}
	}

	return count == 1;
}

bool is_straight(int* cards){
	sort(cards,cards+5);
	map<int,int> freq;
	for(int i=0;i<5;i++){
		freq[cards[i]]++;
	}
	
	int count = 0;
	for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second > 1){
			return false;
		}
	}

	if(freq[1]==1){
		int ans[][5] = {{1,2,3,4,5},{1,10,11,12,13}};

		bool isok1 = true;
		for(int i=0;i<5;i++){
			if(cards[i] != ans[0][i]) isok1 = false;
		}

		bool isok2 = true;
		for(int i=0;i<5;i++){
			if(cards[i] != ans[1][i]) isok2 = false;
		}

		return (isok1 || isok2);
	}

	else{
		for(int i=0;i+1<5;i++){
			if(cards[i+1] - cards[i] != 1) return false;
		}
	}

	return true;
}

bool is_fullhouse(int* cards){
	sort(cards,cards+5);
	map<int,int> freq;
	for(int i=0;i<5;i++){
		freq[cards[i]]++;
	}
	
	int count = 0;
	bool isok1=false,isok2=false;
	for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second == 3){
			isok1 = true;
		}
		else if(it->second == 2){
			isok2 = true;
		}
	}

	return isok1 && isok2;
}

bool is_4card(int* cards){
	sort(cards,cards+5);
	map<int,int> freq;
	for(int i=0;i<5;i++){
		freq[cards[i]]++;
	}
	int count = 0;
	for(map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if(it->second == 4){
			return true;
		}
	}

	return false;
}
int main()
{
	int cards[5];
	while(~scanf("%d,%d,%d,%d,%d",cards,cards+1,cards+2,cards+3,cards+4)){
		if(is_1pair(cards)) cout << "one pair" << endl;
		else if(is_2pair(cards)) cout << "two pair" << endl;
		else if(is_3card(cards)) cout << "three card" << endl;
		else if(is_straight(cards)) cout << "straight" << endl;
		else if(is_fullhouse(cards)) cout << "full house" << endl;
		else if(is_4card(cards)) cout << "four card" << endl;
		else cout << "null" << endl;

	}
}