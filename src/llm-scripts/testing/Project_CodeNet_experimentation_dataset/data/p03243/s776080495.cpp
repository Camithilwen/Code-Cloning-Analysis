#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> vec; vec.pb(111); vec.pb(222); vec.pb(333);
    vec.pb(444); vec.pb(555); vec.pb(666); vec.pb(777); vec.pb(888); vec.pb(999);
    int n; cin >> n;
    int t = *lower_bound(vec.begin(), vec.end(), n);
    cout << t << endl;
    return 0;
}
