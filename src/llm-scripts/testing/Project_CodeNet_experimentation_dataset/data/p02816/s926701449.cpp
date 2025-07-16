#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

vector<int> Z_algorithm(vector<ll> S) {
	int c = 0, n = S.size();
	vector<int> Z(n, 0);
	for (int i = 1; i < n; i++) {
		int l = i - c;
		if (i + Z[l] < c + Z[c]) {
			Z[i] = Z[l];
		} else {
			int j = max(0, c + Z[c] - i);
			while (i + j < n && S[j] == S[i + j])j++;			
			Z[i] = j;
			c = i;
		}
	}
	Z[0] = n;
	return Z;
}

int main(){
  int n;
  cin >> n;
  vector<ll> a(mx), b(mx);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  
  vector<ll> axor(n),bxor(n);
  rep(i,n){ axor[i]=a[i]^a[i+1]; } axor[n-1]=a[n-1]^a[0]; 
  rep(i,n){ bxor[i]=b[i]^b[i+1]; } bxor[n-1]=b[n-1]^b[0]; 
  auto tmp = bxor;
  rep(j,2)rep(i,n) tmp.emplace_back(axor[i]);

  vector<pair<int,ll>> kx;
  auto res = Z_algorithm(tmp);
  for(int i=n; i<n*2; i++)if(res[i]>=n){
    kx.push_back({i-n,b[0]^a[i-n]});
  }

  sort(kx.begin(),kx.end());
  for(auto ans:kx){
    cout << ans.F << " " << ans.S << endl;
  }
  return 0;
}
