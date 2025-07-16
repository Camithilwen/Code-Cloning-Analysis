#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << '\n';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


int main(){
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    vector<ll> ans(n, INF), in(n, 0);

    rep(i,n - 1 + m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        // graph[b].emplace_back(a);
        in[b]++;
    }
    ll root;
    rep(i,n)if(in[i] == 0){
        root = i;
        ans[root] = 0;
    }
    // print(in);
    queue<Pll> que;
    que.push(Pll(root, 0));
    while(!que.empty()){
        Pll t = que.front();que.pop();
        for(auto to : graph[t.first]){
            if(in[to] == 1){
                ans[to] = t.first + 1;
                que.push(Pll(to, t.second + 1));
            }
            in[to]--;
        }
    }

    print(ans);
}