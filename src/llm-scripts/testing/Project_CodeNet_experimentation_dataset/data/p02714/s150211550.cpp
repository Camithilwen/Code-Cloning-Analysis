#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N;
    string S;
    cin >> N >> S;
    ll cnt[3] {0, 0,0};
   
    rep(i, N){
        if(S[i] == 'R') {cnt[0]++;}
        if(S[i] == 'G') {cnt[1]++;}
        if(S[i] == 'B') {cnt[2]++;}
    }

    ll tot = cnt[0]*cnt[1]*cnt[2];
    rep(i, N)rep2(j, i+1, N){
        int k = j+j-i;
        if(k < N)
        {
            if(S[i] == S[j]) continue;
            if(S[k] == S[j]) continue;
            if(S[i] == S[k]) continue;
            --tot;
        }
    }
    cout << tot << endl;
    return 0;
}