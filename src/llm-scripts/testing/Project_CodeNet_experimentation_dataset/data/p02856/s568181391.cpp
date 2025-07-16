#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define fastcin() ios_base::sync_with_stdio(false); cin.tie(0)
using namespace std;
typedef pair<int, int> ii;

int Ceil(int a, int b) { return (a + b - 1) / b; }

int m;
signed main()
{
	int s = 0, dig = 0; 
	cin >> m; 
	for(int i = 1; i <= m; i++) 
	{
		int d, c; cin >> d >> c; 
		dig += c;
		s += c * d; 
	}
	cout << (dig - 1) + Ceil(s-9, 9); 
}
