#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define rer(i,l,n) for(int i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pii;

int main(){
	vint w(10),k(10);
	int sw=0,sk=0;
	rep(i,0,10) cin>>w[i];
	rep(i,0,10) cin>>k[i];
	sort(all(w));
	sort(all(k));
	rep(i,7,10) sw+=w[i];
	rep(i,7,10) sk+=k[i];
	o(sw<<" "<<sk);
}