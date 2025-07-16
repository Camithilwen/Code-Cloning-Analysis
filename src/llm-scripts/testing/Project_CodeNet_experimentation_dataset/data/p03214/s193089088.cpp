#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), (int)0);
    int frame_num = 0;
    int frame_min_dif = 1e8;
    rep(i, n) {
        int tmp_num = a[i] * n;
        int dif = abs(tmp_num - sum);
        if ( dif < frame_min_dif ) {
            frame_num = i;
            frame_min_dif = dif;
        }
    }
    cout << frame_num << endl;
    return 0;
}
