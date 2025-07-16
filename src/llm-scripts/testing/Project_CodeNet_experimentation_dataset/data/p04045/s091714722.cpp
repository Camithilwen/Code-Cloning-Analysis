#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
set<int> si;
int n,k;
int fin = -1;
int s_int(string s){
    return atoi(s.c_str());
}
int check(int n){
    bool ok = 1;
    while(n >= 0){
        if(si.find(n%10) != si.end()){
            return 0;
        }
        n /= 10;
        if(n == 0) break;
    }
    return 1;
}
vector<int> solve(){
    vector<int> ans;
    queue<string> que;
    rep(i,10){
        string s = "";
        s += char('0' + i);
        que.push(s);
    }
    while(1){
        string fa = que.front(); que.pop();
        if(fa.size() > fin) return ans;
        if(!check(s_int(fa))){
            continue;
        }
        if(s_int(fa) >=n){
            if(fin == -1) fin = fa.size(); 
            ans.push_back(s_int(fa));
        }
        rep(i,10){
            que.push(string(fa + char('0' + i)));
        }
    }
}
int main(){
    cout << fixed << setprecision(10);
    cin >> n >> k;
    rep(i,k){
        int x;
        cin >> x;
        si.insert(x);
    }
    vector<int> ans = solve();
    sort(ans.begin(),ans.end());
    cout << ans[0] << endl;
    return 0;
}