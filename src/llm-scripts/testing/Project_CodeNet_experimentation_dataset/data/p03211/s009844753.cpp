#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    string s;
    cin >> s;
    int n=s.size()-2;

    int ans = inf;
    rep(i,n){
        int x=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
        ans = min(ans,abs(x-753));
    }
    cout << ans << endl;

        return 0;
    }