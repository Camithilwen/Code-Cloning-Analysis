#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
#define rep2(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr ll INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;
const int MAXD = 200010;

ll compare(vector<vector<int>> &A,vector<vector<int>> &B,int sz = MAXD * 2) {
    int ans = INF;
    rep(i,sz) {
        sort(B[i].begin(),B[i].end());
        for (int a:A[i]) {
            int idx = lower_bound(B[i].begin(),B[i].end(),a + 1) - B[i].begin();
            if (idx >= (int)B[i].size()) continue;
            ans = min(ans,B[i][idx] - a);
        }
    }
    return ans;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> XU(MAXD),XD(MAXD),YR(MAXD),YL(MAXD),mR(2*MAXD),mD(2*MAXD),mU(2*MAXD),mL(2*MAXD),aR(2*MAXD),aU(2*MAXD),aD(2*MAXD),aL(2*MAXD);
    rep(i,N) {
        int x,y; char s; 
        cin >> x >> y >> s;
        if (s == 'U') {
            XU[x].push_back(y);
            mU[y - x + MAXD].push_back(x);
            aU[y + x].push_back(x);
        } else if (s == 'R'){
            YR[y].push_back(x);
            mR[y - x + MAXD].push_back(x);
            aR[y + x].push_back(x);
        } else if (s == 'D') {
            XD[x].push_back(y);
            mD[y - x + MAXD].push_back(x);
            aD[y + x].push_back(x);
        } else {
            YL[y].push_back(x);
            mL[y - x + MAXD].push_back(x);
            aL[y + x].push_back(x);
        }
    }
    ll ans = INF;
    ans = min(ans,compare(XU,XD,MAXD)*5LL);
    ans = min(ans,compare(YR,YL,MAXD)*5LL);
    ans = min(ans,compare(mR,mD)*10LL);
    ans = min(ans,compare(mU,mL)*10LL);
    ans = min(ans,compare(aR,aU)*10LL);
    ans = min(ans,compare(aD,aL)*10LL);
    if (ans == INF) cout << "SAFE" << '\n';
    else cout << ans << '\n';
    return 0;
}