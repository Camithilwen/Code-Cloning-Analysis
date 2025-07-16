#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void solve() {
        int n, k; scanf("%d%d", &n, &k);
        vector<int> v, csum(n+ 1);

        for (int i= 0; i< n; i++) {
                int x; scanf("%d", &x);
                x++;
                v.push_back(x);
        }

        for (int i= 1; i<= n; i++) csum[i]= csum[i- 1]+ v[i- 1];

        double an= 0;

        for (int i= 1; i<= n- k+ 1; i++) {
                an= max(an, (double)csum[i+ k- 1]- csum[i- 1]);
        }
        an/= 2;
        printf("%0.10f", an);
}

int32_t main(){
//ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
