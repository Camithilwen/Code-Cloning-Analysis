#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(string s, string t, int n){
    // sの文字のうち, かぶっていない文字の数をiとする
    // 全探索する
    for (int i = 0; i < n; i++){
        if (s.substr(i) == t.substr(0,n-i)) return n + i;
    }
    
    // n文字すべてかぶらない-> 2*n
    return 2*n;
}

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    
    cout << solve(s,t,n) << endl;
    return 0;
}