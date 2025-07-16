#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const int N= 51;
const int M= 101;

int dp[N][N][M];

void solve() {
        int n, k; cin >> n>> k;

        memset(dp, -1, sizeof(dp));
        vector<int> v(n);
        for (auto& i: v) cin >> i;

        function<int(int, int, int)> calc= [&](int i, int j, int cnt)->int {
                if (cnt< 0) return -1e18;
                if (cnt== 0) return 0;
                if (i> j) return 0;

                int &ret= dp[i][j][cnt];
                if (ret!= -1) return ret;
                ret= 0;

                ret= max(ret, calc(i+ 1, j, cnt- 1)+ v[i]);
                ret= max(ret, calc(i+ 1, j, cnt- 2));
                ret= max(ret, calc(i, j- 1, cnt- 1)+ v[j]);
                ret= max(ret, calc(i, j- 1, cnt- 2));
                return ret;
        };

        cout << calc(0, n- 1, k)<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
