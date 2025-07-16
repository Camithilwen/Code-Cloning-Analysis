#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;


template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;

int main(){
    ll x,y;
    cin >> x >> y;
    if(x<=y){
        if(x<0 && y>0 && abs(y)>=abs(x)){
            cout << 1+y+x << endl;
        }
        else if(x<0 && y>0 && abs(y)<abs(x)){
            cout << 1-y-x << endl;
        }
        else{
            cout << y-x << endl;
        }
    }
    else{
        if(x>0 && y>=0){
            cout << min(1LL+x+y,2LL+x-y) << endl;
        }
        else if(x>0 && y<0 && abs(x)>=abs(y)){
            cout << 1+x+y << endl;
        }
        else if(x>0 && y<0 && abs(x)<abs(y)){
            cout << 1-x-y << endl;
        }
        else if(x==0){
            cout << 1-y << endl;
        }
        else{
            cout << 2+x-y << endl;
        }
    }
    return 0;
}