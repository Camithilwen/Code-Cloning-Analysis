#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

 
int main()
{
	FAST;
	ll n, m, x, y;
	cin >> n >> m >> x >> y;
	ll a1= -555, a2 = 100; ll f;
	for(ll i = 0; i < n; i ++){
		cin >> f;
		a1 = max(a1, f);
	}
	for(ll i = 0; i < m; i ++){
		cin >> f;
		a2 = min(a2, f);
	}
	if(a1 < a2 && a2 <= y && a2 > x ){
		cout << "No War";
		return 0;
	}
	cout << "War";
	return 0;
}