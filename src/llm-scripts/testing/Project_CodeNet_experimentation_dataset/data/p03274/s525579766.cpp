#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N,K; vector<int> pl,mi;
void input()
{
    cin >> N >> K;
    for(int i=0; i<N; ++i){
        int x; cin >> x;
        if(x > 0) pl.emplace_back(x);
        else if(x < 0) mi.emplace_back(-x);
    }
    reverse(mi.begin(),mi.end());
}

void solve()
{
    if(N != pl.size() + mi.size()) --K;
    int ans, left, right;
    if(pl.empty() && mi.empty()) ans = 0;
    else if(pl.empty()) ans = mi[K-1];
    else if(mi.empty()) ans = pl[K-1];
    else {
        int mi_size = mi.size();
        int pl_size = pl.size();
        if(pl_size >= K)  {
            left = -1; right = K-1;
            ans = pl[right];
        }
        else {
            left = K - pl_size - 1; right = pl_size - 1;
            if(pl[right] > mi[left]) ans = pl[right] + 2 * mi[left];
            else ans = 2 * pl[right] + mi[left];
            // cout << mi[left] << " " << pl[right] << endl;
        }

        while(1){
            ++left; --right; 
            if(left < mi_size){ 
                if(right >= 0){
                    if(pl[right] > mi[left]) ans = min(ans, pl[right] + 2 * mi[left]);
                    else ans = min(ans, 2 * pl[right] + mi[left]);
                    // cout << mi[left] << " " << pl[right] << endl;
                }
                else if(right == -1) ans = min(ans, mi[left]);
            }
            else break;
        }
    }

    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}