#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {

    int N,L;
    cin >> N >> L;

    int R[N];
    rep(i,N){
        R[i] = (L + i);
    }

    int abs_min = 10000;
    int abs_idx;
    rep(i,N){
        if(abs_min > (R[i]*R[i])){
            abs_min = (R[i]*R[i]);
            abs_idx = i;
        }
    }

    int sum = 0;
    rep(i,N){
        sum += R[i];
    }

    sum -= R[abs_idx];

    cout << sum << endl;

}