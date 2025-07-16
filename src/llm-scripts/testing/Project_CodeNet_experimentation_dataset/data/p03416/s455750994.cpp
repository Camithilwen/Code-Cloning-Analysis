#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    int ans = 0;
    forn(i, a, b+1) {
        string s = to_string(i);
        string r = s;
        reverse(r.begin(), r.end());
        ans += s==r;
    }
    cout << ans << endl;
}