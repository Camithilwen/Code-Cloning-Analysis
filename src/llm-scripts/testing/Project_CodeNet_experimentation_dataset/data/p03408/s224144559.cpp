#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int n, m;
    cin >> n;
    vector<string> vec_n(n);
    rep(i, n) cin >> vec_n[i];
    cin >> m;
    vector<string> vec_m(100);
    rep(i, m) cin >> vec_m[i];
    
    int max = -100;
    rep(i, n){
        int cnt = 0;
        rep(j, n){
            if(vec_n[i] == vec_n[j]) cnt++;
        }
        rep(j, m){
            if(vec_n[i] == vec_m[j]) cnt--;
        }
        
        if(cnt > max) max = cnt;
    }
    
    
    if(max < 0){
        cout << 0 << endl;
    }else cout << max << endl;
}