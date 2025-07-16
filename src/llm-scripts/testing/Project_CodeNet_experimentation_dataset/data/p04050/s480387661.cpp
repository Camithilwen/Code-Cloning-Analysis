#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

int n, m;

vector<int> ao, ae;

void Answer(vector<int> A, vector<int> B){
	vector<int> br;
	for(int x:B) if(x) br.pb(x);
	for(int x:A) printf("%d ", x); putchar(10);
	printf("%d\n", sz(br));
	for(int x:br) printf("%d ", x);
	exit(0);
}

int main()
{
	read(n, m);
	rep(i, m){
		int x; read(x);
		if(x&1) ao.pb(x); else ae.pb(x);
	}
	if(ao.size() > 2u){
		puts("Impossible"); return 0;
	}
	if(ao.size() == 0u){
		if(ae.size() == 1u){
			Answer(ae, {1, ae[0]-1});
		} else {
			vector<int> bt = ae;
			bt[0]--; bt.back()++;
			Answer(ae, bt);
		}
	} else if(ao.size() == 1u){
		if(ae.size() == 0u){
			Answer(ao, {1, ao[0]-1});
		} else {
			vector<int> a;
			a.pb(ao[0]); a.insert(a.end(), all(ae));
			vector<int> bt = a;
			bt[0]--; bt.back()++;
			Answer(a, bt);
		}
	} else if(ao.size() == 2u){
		vector<int> a;
		a.pb(ao[0]); a.insert(a.end(), all(ae)); a.pb(ao[1]);
		vector<int> bt = a;
		bt[0]--; bt.back()++;
		Answer(a, bt);
	}
	return 0;
}
