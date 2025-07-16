#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	string S;
	cin >> S;
	int ans = 7;
	if(S == "MON") ans = 6;
	if(S == "TUE") ans = 5;
	if(S == "WED") ans = 4;
	if(S == "THU") ans = 3;
	if(S == "FRI") ans = 2;
	if(S == "SAT") ans = 1;
	cout << ans << "\n";
}