#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T = S.substr(0, N);
    string U = S.substr(N, N);
    reverse(U.begin(), U.end());
    //cout << T << endl << U << endl;
    
    unordered_map<string, ll> um1(0), um2(0);
    
    for (int i = 0; i < (1 << N); i++) {
        string a="", b="";
        for (int j = 0; j < N; j++) {
            if (((i >> j) & 1) == 0) a += T[j];
            else b += T[j];
        }
        um1[a + "_" + b]++;
    }
    
    ll ans = 0;
    
    for (int i = 0; i < (1 << N); i++) {
        string a="", b="";
        for (int j = 0; j < N; j++) {
            if (((i >> j) & 1) == 0) a += U[j];
            else b += U[j];
        }
        ans += um1[a + "_" + b];
    }
    cout << ans << endl;
    return 0;
}