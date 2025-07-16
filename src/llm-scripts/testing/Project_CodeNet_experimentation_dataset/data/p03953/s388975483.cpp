#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll x[100010];
int a[100010], nsw[100010], now[100010], vid[100010], vnum[100010], repl[100010];
bool looked[100010]={};
vector<vector<int>> v;

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i) cin >> x[i];
	int M;
	ll K;
	cin >> M >> K;
	for(int i=0; i<M; ++i) cin >> a[i];
	for(int i=1; i<N; ++i) nsw[i]=i;
	for(int i=0; i<M; ++i) swap(nsw[a[i]-1], nsw[a[i]]);
	for(int i=1; i<N; ++i) now[nsw[i]]=i;
	int cnt=0;
	for(int i=1; i<N; ++i){
		if(!looked[i]){
			int b=i;
			v.emplace_back();
			do{
				vnum[b]=v[cnt].size();
				v[cnt].emplace_back(b);
				vid[b]=cnt;
				looked[b]=1;
				b=now[b];
			}while(b!=i);
			++cnt;
		}
	}
	for(int i=1; i<N; ++i){
		ll sz=v[vid[i]].size();
		ll r=(K%sz+vnum[i])%sz;
		repl[v[vid[i]][r]]=i;
	}
	cout << x[0] << endl;
	ll ans=x[0];
	for(int i=1; i<N; ++i){
		ans += x[repl[i]]-x[repl[i]-1];
		cout << ans << endl;
	}
	return 0;
}