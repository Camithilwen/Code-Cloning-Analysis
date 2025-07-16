#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

bool f(P l,P r){
    int a = l.second - l.first;
    int b = r.second - r.first;
    if(a > 0 && b <= 0){
        return true;
    }
    if(a <= 0 && b > 0){
        return false;
    }
    if(a > 0 && b > 0){
        return l.first < r.first;
    }if(a < 0 && b < 0){
        return l.second > r.second;
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<P> lr(n);
    rep(i,n){
        int l = 0;
        int r = 0;
        rep(j,s[i].size()){
            if(s[i][j] == '('){
                ++r;
            }else{
                if(r > 0) --r;
                else ++l;
            }
        }
        lr[i].first = l;
        lr[i].second = r;
    }

    sort(lr.begin(),lr.end(),f);
    if(lr[0].first!=0){
        cout << "No" << endl;
        return 0;
    }
    int l = 0;
    int r = 0;
    rep(i,n){
        if(r < lr[i].first){
            cout << "No" << endl;
            return 0;
        }
        r -= lr[i].first;
        r += lr[i].second;
    }
    cout << (r==0?"Yes":"No") << endl;
    return 0;
}
