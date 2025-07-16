#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;

    vector<vector<int>> x(n, vector<int>());
    vector<vector<int>> y(n, vector<int>());
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            int xx, yy;
            cin >> xx >> yy;
            x[i].push_back(xx-1);
            y[i].push_back(yy);
        }
    }

    int max_pop = 0;
    for(int i=0; i<(1<<n); i++){
        bool flag = true;
        for(int j=0; j<n; j++){
            if((i & (1<<j)) == (1<<j)){
                // j が正直者のとき
                for(int k=0; k<x[j].size(); k++){
                    if((i & (1<<x[j][k])) != y[j][k] * (1<<x[j][k])){
                        // 証言と違う
                        flag = false;
                    }
                }
            }
        }
        if(flag && max_pop < __builtin_popcount(i)){
            max_pop = __builtin_popcount(i);
        }
    }
    cout << max_pop << endl;

    return 0;
}