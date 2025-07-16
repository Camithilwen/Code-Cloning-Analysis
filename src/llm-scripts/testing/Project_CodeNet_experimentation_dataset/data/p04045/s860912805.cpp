#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<ll> m;
vector<bool> num(10,true);

int N,K;

void rec(int n){
    if(n > N) return;

    rep(i,10){
        if(num[i]){
            if(n*10 + i == 0) continue;
            m.emplace_back(n*10 + i);
            rec(n*10 + i);
        }
    }
}


int main(){
    int a; cin >> N >> K;


    rep(i,K){
        cin >> a;
        num[a] = false;
    }


    rec(0);

    sort(m.begin(),m.end());

    rep(i,m.size()){
        if(m[i] >= N){
            cout << m[i];
            return 0;
        }
    }
}