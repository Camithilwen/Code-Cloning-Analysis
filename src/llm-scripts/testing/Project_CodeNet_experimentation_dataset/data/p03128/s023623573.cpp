#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> num = {0,2,5,5,4,5,6,3,7,6};
vector<char> nchar = {'0','1','2','3','4','5','6','7','8','9'};

bool check(string s,string t){
    int n1 = s.size(), n2 = t.size();
    if(n1 > n2) return false;
    if(n1 < n2) return true;
    if(s > t) return false;
    return true;
}

int main(){
    int n,m; cin >> n >> m;
    vector<string> dp;
    vector<int> match(m);
    rep(i,m) cin >> match[i];
    dp.push_back("");
    for(int i = 1;i <= n;++i){
        string s = "";
        rep(j,m) {
            if(num[match[j]] <= i) {
                if(dp[i-num[match[j]]] == "" && i != num[match[j]]) continue;
                if(check(s,dp[i-num[match[j]]]+nchar[match[j]])) s = dp[i-num[match[j]]]+nchar[match[j]];
            }
        }
        dp.push_back(s);
    }
    cout << dp[n] << endl;
}