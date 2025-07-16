#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define num(a) a-'0'
#define maxself(a,b) if(b>a)a=b
#define minself(a,b) if(b<a)a=b;
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<long long int>
#define v vector
#define p pair
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"	
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e11;

void solve(){
	int n;
	cin>>n;
	v<v<p<int,int>>> a(n);
	int h;
	rep(i,0,n){
		cin>>h;
		rep(j,0,h){
			int x,pos;
			cin>>x>>pos;
			a[i].pb(mk(x,pos));
		}
	}
	ll ans=0;
	for(int bit=0;bit<(1<<n);bit++){
		int counter=0;
		int pos=1;
		for(int j=0;j<n;j++){
			if(1<<j & bit){
				for(auto e:a[j]){
					h=((1<<(e.f-1)) & bit);
					if(h==0 && e.s==1){
						pos=0;
					}
					else if(h!=0 && e.s==0){
						pos=0;
						break;
					}
				}
				counter++;
			}
		}
		if(pos){
			maxself(ans,counter);
		}
	}
	cout<<ans<<ln;
}

int main(){
	boost_io;
	solve();
	return 0;
}