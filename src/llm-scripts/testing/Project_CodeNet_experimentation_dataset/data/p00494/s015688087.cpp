#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define MAX 1000000010

int solve(string str){
	int a[3] = {0, 0, 0}, ans = 0;
	for(int i = 0;i < str.size();i++){
		if(str[i] == 'J'){
			if(a[1] || a[2])a[0] = a[1] = a[2] = 0;
			if(!a[1] && !a[2])a[0]++;
		}else if(a[0] && str[i] == 'O'){
			if(!a[2])a[1]++;
			else a[0] = a[1] = a[2] = 0;
		}else if(a[0] && a[1] && a[0] >= a[1] && str[i] == 'I'){
			a[2]++;
			if(a[1] == a[2])ans = max(a[1], ans);
		}else{
			a[0] = a[1] = a[2] = 0;
		}
	}
	return ans;
}

int main(){
	string str;
	cin >> str;
	cout << solve(str) << endl;
	
	return 0;
}