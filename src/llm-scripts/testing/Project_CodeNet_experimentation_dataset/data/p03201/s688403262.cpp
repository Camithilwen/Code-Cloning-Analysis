#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    multiset<int> s(a.begin(), a.end());
    while(!s.empty()) {
        auto it = prev(s.end());
        int a = *it;
        s.erase(it);
        int b = (1LL << (32 - __builtin_clz(a))) - a;
        it = s.find(b);
        if(it != s.end()) {
            ans++;
            s.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}
