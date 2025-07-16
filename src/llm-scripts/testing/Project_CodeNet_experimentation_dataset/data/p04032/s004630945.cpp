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
    
    string s;
    cin >> s;
    int n = s.size();
    
    forn(i, 0, n) {
        if (i+1 < n && s[i] == s[i+1]) {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
        if (i+2 < n && s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << "-1 -1\n";
}
