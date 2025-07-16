#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = /*1'000'000'007LL;*/ 998'244'353LL;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
int L[100000], R[100000]; // [L,R)
pair<int, int> sec[100000];
vector<pair<int, int>> v;

signed main(){
    cin >> N;
    rep(i, N){
        cin >> L[i] >> R[i];
        L[i]--;
        sec[i] ={ L[i],-R[i] };
    }
    sort(sec, sec+N);

    rep(i, N){
        while(v.size() > 0 && v.back().second >= -sec[i].second){
            v.pop_back();
        }
        v.pb({ sec[i].first,-sec[i].second });
    }

    if(v.size() == 1){
        int ans = 0;
        rep(i, N-1){
            ans = max(ans, -sec[i].second - sec[i].first);
        }
        cout << ans + -sec[N-1].second - sec[N-1].first << endl;
        exit(0);
    }

    int ans = 0;
    for(int i=1; i<v.size(); i++){
        ans = max(ans, max(0, v[0].second-v[i-1].first) + max(0, v[i].second-v[v.size()-1].first));
    }
    set<pair<int,int>> l, r;
    rep(i, N){
        l.insert({ L[i],i });
        r.insert({ R[i],i });
    }
    rep(i, N){
        l.erase({ L[i],i });
        r.erase({ R[i],i });
        ans = max(ans, R[i]-L[i] + max(0, r.begin()->first-prev(l.end())->first));
        l.insert({ L[i],i });
        r.insert({ R[i],i });
    }
    cout << ans << endl;
}