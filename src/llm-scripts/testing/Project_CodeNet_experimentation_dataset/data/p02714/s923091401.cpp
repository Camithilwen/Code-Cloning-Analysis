#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n, ans = 0;
    string s;
    vector<int> r, g;
    int b[4010], rn = 0, bn = 0, gn = 0;
    for(int i = 0; i < 4010; i++) b[i] = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') {r.push_back(i); rn++;}
        else if(s[i] == 'G') {g.push_back(i); gn++;}
        else {b[i]++; bn++;}
    }
    for(int i = 0; i < rn; i++){
        for(int j = 0; j < gn; j++){
            int minn = min(r[i], g[j]);
            int maxn = max(r[i], g[j]);
            int l = maxn - minn;
            int l2 = minn + maxn;
            int add = bn;
            if(minn-l >= 0 && b[minn-l] > 0){
                add--;
            } 
            if(l%2==0 && b[l2/2] > 0){
                add--;
            } 
            if(maxn+l < n && b[maxn+l] > 0){
                add--;
            }
            ans += add;
        }
    }
    cout << ans << endl;
    return 0;
}
