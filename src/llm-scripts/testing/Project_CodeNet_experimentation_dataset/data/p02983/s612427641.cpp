#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int l, r;
    cin >> l >> r;
    if(r - l >= 2019) cout << 0 << endl;
    else{
        vector<int> n;
        for(int i = l; i <= r; i++){
            n.push_back(i % 2019);
        }
        vector<int> m;
        rep(i,n.size()){
            for(int j = i+1; j < n.size(); j++) m.push_back((n[i]*n[j])%2019);
        }
        sort(m.begin(), m.end());
        cout << m[0] << endl;
    }
}