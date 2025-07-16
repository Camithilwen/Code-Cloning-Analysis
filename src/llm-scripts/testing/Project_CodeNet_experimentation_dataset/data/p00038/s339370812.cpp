#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int a[5];

bool isStraight(){
	vector<int> n;
	for(int i=0 ; i<5 ; i++){
		n.push_back(a[i]);
	}
	sort( n.begin(), n.end() );
	if( n[0]+1 == n[1] && n[1]+1 == n[2] && n[2]+1 == n[3] && n[3]+1 == n[4]){
		return true;
	}
	if( n[0]==1 && n[1]==10 && n[2]==11 && n[3]==12 && n[4]==13){
		return true;
	}
	return false;
}

string checkCard(){
	int n, count, c[5];
	int c2=0, c3=0, c4=0;

	for(int j=0 ; j<5 ; j++){
		count = 0;
		n = a[j];
		for(int i=0 ; i<5 ; i++){
			if(a[i]==n)count++;
		}
		c[j] = count;
	}
	for(int i=0 ; i<5 ; i++){
		if(c[i]==2)c2++;
		if(c[i]==3)c3++;
		if(c[i]==4)c4++;
	}
	if(c4==4) return "four card";
	else if(c3==3 && c2==2) return "full house";
	else if( isStraight() ) return "straight";
	else if(c3==3) return "three card";
	else if(c2==4) return "two pair";
	else if(c2==2) return "one pair";
	else return "null";
}

int main(){
	string str;
	char s[80];
	while( scanf("%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4] ) != EOF ){
		str = checkCard();
		printf("%s\n",str.c_str());
	}
	return 0;
}