#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s;
    cin >> s;
    vector<int> cnts;
    bool isS = true;
    int cnt = 0;
    rep(i,s.size()){
        if (isS && s[i] == 'T'){
            cnts.push_back(cnt);
            isS = !isS;
            cnt = 0;
        }else if (!isS && s[i] == 'S'){
            cnts.push_back(cnt);
            isS = !isS;
            cnt = 0;
        }
        cnt++;
    }
    cnts.push_back(cnt);
    if (s[s.size()-1] != 'S') cnts.push_back(0);

    int tot = cnts[1] - cnts[0];
    int ans = 0, sz = cnts.size();
    for(int i = 3; i < sz; i+=2){
        tot += cnts[i] - cnts[i-1];
        ans = max(ans, tot);
    }
    tot = cnts[sz-1];
    ans = max(ans, tot);
    for(int i = sz-3; i >= 0; i -= 2){
        tot += cnts[i] - cnts[i+1];
        ans = max(ans, tot);
    }
    cout << ans * 2 << endl;
    return 0;
}