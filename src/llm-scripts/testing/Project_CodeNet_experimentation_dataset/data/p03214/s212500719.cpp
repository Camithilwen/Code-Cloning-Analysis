#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    double s = 0;
    rep(i,N) {
        s += a[i];
    }
    s /= N;
    double min = 10000;
    int min_num = 10000;
    for(int i = N-1; i >= 0; i--) {
        if (abs(s-a[i]) <= min){
            min = abs(s-a[i]);
            min_num = i;
        }
    }
    cout << min_num << endl;
    return 0;
}
