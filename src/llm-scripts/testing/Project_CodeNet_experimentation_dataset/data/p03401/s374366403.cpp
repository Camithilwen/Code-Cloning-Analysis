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
    vector<int>a(n+2);
    for(int i = 1;i<=n;i++) cin >> a[i];
    int s = 0;
    for(int i = 0;i<=n+1;i++) {
        s += abs(a[i]-a[i+1]);
    }
    for(int i = 1;i<=n;i++) {
        int tmp = abs(a[i-1]-a[i+1]) - abs(a[i-1] - a[i]) -abs(a[i]-a[i+1]);
        int ans = s + tmp;
        cout << ans << endl;
    }

}