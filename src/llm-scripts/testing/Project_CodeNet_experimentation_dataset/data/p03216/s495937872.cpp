#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//using ll = long long;
using P = pair<int,int>;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,q;
	string s;
	cin >> n >> s >> q;
	for(int i = 0;i < q;i++){
		int k,ans = 0,d = 0,m = 0,c = 0,dm = 0,mc = 0;
		cin >> k;
		for(int j = 0;j < n;j++){
			if(j >= k){
				if(s[j - k] == 'D'){
					d--;
					dm -= m;
				}
				else if(s[j - k] == 'M'){
					m--;
					mc -= c;
				}
				else if(s[j - k] == 'C'){
					c--;
				}
			}
			if(s[j] == 'D'){
				d++;
			}
			else if(s[j] == 'M'){
				m++;
				dm += d;
			}
			else if(s[j] == 'C'){
				c++;
				mc += m;
				ans += dm;
			}
		}
		cout << ans << endl;
	}

}