#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    vector<int>ans;
    rep(i,n-1) {
        if(a[i] == a[i+1]) {
            ans.push_back(a[i]);
            i++;
        }
    }
    if(ans.size()<2) {
        cout << 0 << endl;
        return 0;
    }
    ll square = (ll)(ans[0]) * (ll)(ans[1]);
    cout << square << endl;
}