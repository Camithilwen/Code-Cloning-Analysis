#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i,n) cin >> L[i];

    int res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            for(int k = j + 1; k < n; ++k) {
                if(L[i] == L[j] || L[j] == L[k] || L[k] == L[i]) continue;
                vector<int> v = {L[i],L[j],L[k]};
                sort(v.begin(), v.end());
                res += (v[0] + v[1] > v[2]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}