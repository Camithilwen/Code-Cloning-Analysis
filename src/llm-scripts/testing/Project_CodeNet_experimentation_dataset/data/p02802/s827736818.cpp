#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<string>> v(n);
    rep(i, m){
        int a; cin >> a;
        string s; cin >> s;
        v.at(a-1).push_back(s);
    }
    int ac = 0, wa = 0;
    vector<int> v_wa(n);
    rep(i, n){
        bool flag = true;
        for(auto j : v.at(i)){
            if(j == "AC") {
                ac++;
                flag = false;
                break;
            }
            wa++;
        }
        if(flag) wa = 0;
        v_wa.at(i) = wa;
        wa = 0;
    }
    int sum = 0;
    for(auto a : v_wa) sum += a;
    cout << ac << ' ' << sum << endl;
    return 0;
}
