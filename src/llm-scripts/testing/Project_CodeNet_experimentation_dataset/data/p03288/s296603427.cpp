// A - Rated for Me
#include <bits/stdc++.h>
using namespace std;

int main(){
	int r; cin>>r;
	string ans = "ARC";
	if(r < 1200) ans = "ABC";
	if(2800 <= r) ans = "AGC";
	cout<< ans <<endl;
}
