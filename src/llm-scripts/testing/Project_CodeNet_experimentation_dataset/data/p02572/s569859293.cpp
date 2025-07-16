#include <bits/stdc++.h>

using namespace std;
int64_t mod = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int64_t>arr(n);
    for(auto & i : arr)
        cin >> i;
    vector<int64_t>sufsum;
    sufsum.push_back(0);
    for(int i = n-1; i > 0; --i){
        auto a = sufsum.back();
        a+=arr[i];
        sufsum.push_back(a);
    }
    reverse(sufsum.begin(),sufsum.end());
    int64_t ans = 0;
    for(int i = 0 ; i < n; ++i){
        ans+=(arr[i]*(sufsum[i]%mod));
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}