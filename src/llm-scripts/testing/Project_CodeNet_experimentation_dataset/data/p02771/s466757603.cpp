#pragma GCC optimize ("Ofast")
#include"bits/stdc++.h"
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10); } } ___;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}

#define ll long long
#define pii pair<int,int>
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define endll '\n'
#define rep(i,n) for(int i=0;i++<n;)
#define scl(i) scanf("%lld",&i)
#define int long long int
#define all(n) n.begin(),n.end()
#define mem(n,i) memset(n,i,sizeof n)
#define em(a) emplace_back(a)
#define pb(a) push_back(a)
#define srep(it,vv) for(auto &it : vv)
#define prep(it,vv) for(auto it : vv)
//vector<vector<int>>arr(n + 5, vector<int>(m + 5,0));

typedef vector<int> vii;
typedef vector<string> vss;
/*

*/
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    set<int>ss;
    int n = 3;
    rep(i, n)
    {
        int a; cin >> a;
        ss.insert(a);
    }
    if (ss.size() == 2) cout << "Yes" << endll;
    else cout << "No" << endll;
}