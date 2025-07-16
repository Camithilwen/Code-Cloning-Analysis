#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

char in[1000100];

int main(){
	fgets(in, sizeof(in), stdin);
	vector<pi> v;
	int cnt = 0, ans = 0;
	
	for(int i = 0; ; i++){
		if(i && in[i] != in[i - 1]){
			v.pb(mp(in[i - 1], cnt));
			cnt = 1;
		}
		else cnt++;
		if(!in[i]) break;
	}
	
	rep(i, v.size() - 2) if(v[i].first == 'J'
		&& v[i + 1].first == 'O'
		&& v[i + 2].first == 'I'){
		
		if(v[i + 1].second <= v[i].second && v[i + 1].second <= v[i + 2].second)
		ans = max(ans, v[i + 1].second);
	}
	
	cout << ans << endl;
	
	return 0;
}