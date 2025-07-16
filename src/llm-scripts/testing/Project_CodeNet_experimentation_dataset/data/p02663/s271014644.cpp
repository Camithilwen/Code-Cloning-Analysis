#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h1,m1,h2,m2,k;
	cin>>h1>>m1>>h2>>m2>>k;
	cout<<(h2*60+m2)-(h1*60+m1)-k<<endl;
	return 0;
}
