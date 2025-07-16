#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

bool dp[5100][10100];

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> ex(8,0);
    rep(i,m) {
        int a;
        cin >> a;
        int b;
        if(a == 1) b = 2;
        else if(a == 7) b = 3;
        else if(a == 4) b = 4;
        else if(a == 2 || a == 3 || a == 5) b = 5;
        else if(a == 6 || a == 9) b = 6;
        else b = 7;
        chmax(ex[b],a);
    }
     rep(i,5100) rep(j,10100) dp[i][j] = false;
    dp[0][0] = true;
    rep(i,5099) {
        rep(j,n+1) {
            if(!dp[i][j]) continue;
            rep2(k,2,8) if(ex[k] > 0) {
                dp[i+1][j+k] = true;
            }
        }
    }
    int mx;
    rrep(i,5100) {
        if(dp[i][n]) {
            mx = i+1;
            break;
        }
    }
    int now = n;
    for(int i = mx-1; i > 0; i--) {
        int can = 0;
        int use;
        rep2(j,2,min(8,now+1)) {
            if(ex[j] > can && dp[i-1][now-j]) {
                can = ex[j];
                use = j;
            }
        }
        now -= use;
        cout << can;
    }
    cout << endl;
}
