#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef LOCAL
	freopen("inp.txt", "r", stdin );
	freopen("ans.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if(s=="SUN") cout << 7 << '\n';
	if(s=="MON") cout << 6 << '\n';
	if(s=="TUE") cout << 5 << '\n';
	if(s=="WED") cout << 4 << '\n';
	if(s=="THU") cout << 3 << '\n';
	if(s=="FRI") cout << 2 << '\n';
	if(s=="SAT") cout << 1 << '\n';
}
