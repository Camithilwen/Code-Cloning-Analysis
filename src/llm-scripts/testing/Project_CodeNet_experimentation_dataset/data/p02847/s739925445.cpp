#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	string s;
	cin >> s;
	if(s == "SUN") cout << "7\n";
	else if(s == "SAT") cout << "1\n";
	else if(s == "FRI") cout << "2\n";
	else if(s == "THU") cout << "3\n";
	else if(s == "WED") cout << "4\n";
	else if(s == "TUE") cout << "5\n";
	else if(s == "MON") cout << "6\n";
	return 0;	
}