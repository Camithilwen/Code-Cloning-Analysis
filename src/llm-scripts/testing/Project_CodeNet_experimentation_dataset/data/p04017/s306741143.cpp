#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int N = 100001;
vector<vector<int> > fat(N,vector<int> (20,-1));

int par(int now,int n){
	for(int i=18;i>=0;i--){
		if(now == -1) continue;
		if(n>>i&1) now = fat[now][i];
	}
	return now;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n;
    int x[n];
    for(int i=0;i<n;i++) cin >> x[i];

    int L;
    cin >> L;
    for(int i=0;i<n;i++) fat[i][0] = upper_bound(x,x+n,x[i]+L) - x - 1;
    for(int i=0;i<18;i++)for(int j=0;j<n;j++) fat[j][i+1] = fat[fat[j][i]][i];

    cin >> q;
    vector<int> ans;
    while(q--){
    	int a, b;
    	cin >> a >> b;
    	a--;b--;
    	if(a > b)swap(a,b);
    	int le = 0, ri = n, mid;
    	while(ri - le > 1){
    		mid = (ri + le) / 2;
    		int p = par(a, mid);
    		if(p >= b) ri = mid;
    		else le = mid;
    	}
    	ans.pb(ri);
    }
    for(auto& i:ans){
    	cout << i << endl;
    }
    return 0;
}
