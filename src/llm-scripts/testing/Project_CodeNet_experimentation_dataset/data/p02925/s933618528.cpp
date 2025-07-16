#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }



int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	vector<VI> a(n, VI(n-1));
	rep(i, n) rep(j, n-1){ cin >>a[i][j]; a[i][j]--;}
	rep(i, n) reverse(all(a[i]));
	int ans = 0;
	VI seq(n); iota(all(seq), 0);
	for(int g=0, nxt =1; nxt; g++){
		nxt = 0;
		VI usd(n);
		VI nsq;
		swap(seq, nsq);
		rep(pi, sz(nsq)){
			int i = nsq[pi];
			if(usd[i] !=0 || sz(a[i]) < 1) continue;
			int tcr = a[i].back();
			if(a[tcr].back() == i && usd[tcr]==0){
				usd[i] = usd[tcr] = 1;
				a[tcr].pop_back();
				a[i].pop_back();
				nxt = 1;
				ans = max(ans, g+1);
				seq.push_back(i); seq.push_back(tcr);
			}
		}
		sort(all(seq));
		seq.erase(unique(all(seq)), seq.end());
	}
	rep(i, n) if(sz(a[i])>0) ans =-1;
	cout <<ans <<"\n";
	return 0;
	
}
