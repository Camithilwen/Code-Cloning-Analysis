#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans = 2*n;
    for(int i = 1;i <= n;i++){
        string sx = s.substr(n-i,i);
        string tx = t.substr(0,i);
        if(sx == tx)ans = 2*n - i;
    }
    cout << ans << endl;
    return 0;
}