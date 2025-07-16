#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n,a,b,c,d,e;
	cin >> n >> a >> b >> c >> d >> e;
	cout << (n-1)/min({a,b,c,d,e})+5 << endl;

	return 0;
}