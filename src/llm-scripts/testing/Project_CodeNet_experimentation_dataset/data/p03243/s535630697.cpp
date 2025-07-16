#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main( ) {
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi a={111,222,333,444,555,666,777,888,999};
    int n;
    cin >> n;
    rep(i, 0, 9){
        if(n<=a[i]){
            cout << a[i] << endl;
            break;
        }
    }
    return 0;
}