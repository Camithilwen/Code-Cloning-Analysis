
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;


bool solve(){
	int n;
	cin>> n;
	if(!n) return false;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>> a[i];
	}
	string str;
	cin>> str;
	
	for(int i=0;i<str.size();i++){
		int k = a[i%n];
		k %= 52;
		char c = str[i];
		if(k>26){
			if(islower(c)){
				c = toupper(c);
			}else{
				c = tolower(c);
			}
			k -= 26;
		}
		if(islower(c)){
			if(islower(c-k)){
				c -= k;
			}else{
				k -= c - 'a';
				c = 'Z' - (k - 1);
			}
		}else if(isupper(c)){
			if(isupper(c-k)){
				c -= k;
			}else{
				k -= c - 'A';
				c = 'z' - (k - 1);
			}
		}
		cout<< c;
	}
	cout<< endl;

	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	while(solve()){}

	return 0;
}

 