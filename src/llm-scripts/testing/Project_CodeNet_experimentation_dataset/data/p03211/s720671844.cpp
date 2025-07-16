#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    string s;
    int ans=INF;
    cin >> s;
    
    rep(i,s.size()-2){
        int now = (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0')*1;
        ans = min(ans,abs(753-now)); 
    }
    
    cout << ans;
    
    return 0;
}