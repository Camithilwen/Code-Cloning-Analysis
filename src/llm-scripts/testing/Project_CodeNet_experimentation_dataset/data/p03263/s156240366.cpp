#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    int data[h][w]; rep(i,h) rep(j,w) cin >> data[i][j];

    vector<vector<int>> ans(4,vector<int>());
    rep(i,h) rep(j,w){
        if(j == w-1){
            if(i == h-1) continue;
            if(data[i][j]%2 == 1){
                data[i][j]--;
                data[i+1][j]++;
                ans[0].push_back(i+1);
                ans[1].push_back(j+1);
                ans[2].push_back(i+2);
                ans[3].push_back(j+1);
            }
        }
        else if(data[i][j]%2 == 1){
            data[i][j]--;
            data[i][j+1]++;
            ans[0].push_back(i+1);
            ans[1].push_back(j+1);
            ans[2].push_back(i+1);
            ans[3].push_back(j+2);
        }
    }
    cout << ans[0].size() << endl;
    rep(i,ans[0].size()) cout << ans[0][i] << " " << ans[1][i] << " " << ans[2][i] << " " << ans[3][i] <<endl;
}