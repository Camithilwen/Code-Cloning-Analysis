
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

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){//popcount%2
	return __builtin_parity(x);
}



template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e15;

const ll mod=1e9+7;


int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n-1));
    rep(i,n)rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    }
    rep(i,n){
        reverse(a[i].begin(),a[i].end());
    }
    vector<pii> q;
    auto check=[&](ll i){
        if(a[i].size()==0){
            return ;
        }
        ll j=a[i].back();
        if(a[j].back()!=i){
            return ;
        }
        if(i>j) swap(i,j);
        pii P=make_pair(i,j);
        q.push_back(P);
    };
    rep(i,n){
        check(i);
    }
    ll day=0;
    while(q.size()){
        day++;
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());
        vector<pii> preQ;
        swap(preQ,q);
        for(pii x:preQ){
            ll i=x.first;
            ll j=x.second;
            a[i].pop_back();
            a[j].pop_back();
        }
        for(pii x:preQ){
            ll i=x.first;
            ll j=x.second;
            check(i);
            check(j);
        }
    }
    rep(i,n){
        if(a[i].size()){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}