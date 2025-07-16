#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T&a , T b){ if(a<b){ a=b; return true; } else{ return false; } }
template<class T> inline bool chmin(T&a , T b){ if(a>b){ a=b; return true; } else{ return false; } } 

const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

bool check(vector<P> s){
    int h=0;
    for (P p : s){
        int b = h+p.first;
        if(b<0) return false;
        h += p.second;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<P> ls, rs;
    int total = 0;
    rep(i,n){
        string s;
        cin >> s;
        int h = 0, b = 0;
        for(char c : s){
            if(c=='(') ++h; else --h;
            b = min(b,h);
        }
        if(h>0) ls.emplace_back(b,h);
        else rs.emplace_back(b-h,-h);
        total += h;
    }
    sort(ls.rbegin(),ls.rend());
    sort(rs.rbegin(),rs.rend());
    if(check(ls) && check(rs) && total==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
