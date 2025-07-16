#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, m;
    cin >> n >> m;
    int all_path[2];
    all_path[0] = 1;
    all_path[1] = n;
    rep(i, m){
        int l, r;
        cin >> l >> r;
        if(all_path[0] < l) all_path[0] = l;
        if(r < all_path[1]) all_path[1] = r;
    }
    if (all_path[1] < all_path[0])cout << 0 << endl;
    else cout << all_path[1] - all_path[0] + 1 << endl;
}