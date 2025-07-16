#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

// 解説AC
int main()
{
    int H, W;
    cin >> H  >> W;

    vector<vector<int>> a(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];

    int ph=-1, pw=-1;
    bool c=false;

    vector<vector<int>> ans;

    for (int h = 0; h < H; h++) {
        if (h % 2 == 0) {
            for (int w = 0; w < W;w++){
                if (c) ans.push_back(vector<int>{ph + 1, pw + 1, h + 1, w + 1});
                if(c){
                    if(a[h][w]%2==1){
                        c = false;
                    }
                }else{
                    if(a[h][w]%2==1){
                        c = true;
                    }
                }
                ph = h;
                pw = w;
            }
        } else {
            for (int w = W - 1;w>=0;w--){
                if (c) ans.push_back(vector<int>{ph + 1, pw + 1, h + 1, w + 1});
                if (c) {
                    if (a[h][w] % 2 == 1) {
                        c = false;
                    }
                } else {
                    if (a[h][w] % 2 == 1) {
                        c = true;
                    }
                }
                ph = h;
                pw = w;
            }
        }
    }

    cout << ans.size() << endl;
    for(auto a:ans){
        cout << join(a, " ") << endl;
    }
}
