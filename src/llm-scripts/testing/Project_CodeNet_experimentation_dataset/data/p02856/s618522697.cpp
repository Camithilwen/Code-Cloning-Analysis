#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int M;
vector<int> D; vector<ll> C;
int n = 0;
ll ans = 0;

ll memo[10][10] ={};
ll calcC(int n, int m){
    if(memo[n][m] != 0) return memo[n][m];
    deque<int> que;
    que.pb(n);
    rep(i, 9) que.pb(m);
    ll ret = 0;
    while(que.size() > 1){
        int a = que[0];
        int b = que[1];
        que.pop_front();
        que.pop_front();
        if(a+b >= 10){
            que.push_front((a+b)%10);
            que.push_front(1);
        }
        else{
            que.push_front(a+b);
        }
        ret++;
    }
    return memo[n][m] = ret;
}

void calc(deque<int> &que){
    while(que.size() > 1){
        int a = que[0];
        int b = que[1];
        que.pop_front();
        que.pop_front();
        if(a+b >= 10){
            que.push_front((a+b)%10);
            que.push_front(1);
        }
        else{
            que.push_front(a+b);
        }
        ans++;
    }
}

signed main(){
    cin >> M;
    rep(i, M){
        int d; ll c;
        cin >> d >> c;
        if(d == 0){
            ans += c;
        }
        else{
            if(n == 0){
                n = d;
                c--;
            }
            if(c > 0){
                D.pb(d);
                C.pb(c);
            }
        }
    }

    rep(i, D.size()){
        ll k = C[i] / 9;
        ans += k * calcC(n, D[i]);
        deque<int> d;
        d.pb(n);
        rep(j, C[i]-9*k) d.pb(D[i]);
        calc(d);
        n = d.front();
    }
    cout << ans << endl;
}