#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
ll N,A,B,C,D,E;


//processing
ll hoge;


//dpTable
//int dp[100050];

int main(){
    cin >> N >> A >> B >> C >> D >> E;
    hoge = min(A,min(B,min(C,min(D,E))));
    ll ans = (N + hoge - 1) / hoge;
    cout << ans + 4 << endl;
    return 0;
}