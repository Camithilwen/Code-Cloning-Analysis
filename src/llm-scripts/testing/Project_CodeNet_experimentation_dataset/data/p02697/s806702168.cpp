#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
	rep(i, m/2){
		cout << i+1 << " " << m-i << endl;
	}
	rep(i, (m+1)/2){
		cout << i+1+m << " " << 2*m+1-i << endl;
	}
}
