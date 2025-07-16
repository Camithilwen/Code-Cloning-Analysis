#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l(n+1),r(n+1);
    for(int i=1; i<=n-1; i++){
        if(s[i-1]=='W') l[i] = l[i-1]+1;
        else l[i] = l[i-1];
    }
    for(int i=n; i>=1; --i){
        if(s[i-1]=='E') r[n-i+1] = r[n-i]+1;
        else r[n-i+1] = r[n-i]; 
    }
    int ans = 1e9;
    for(int i=0; i<=n-1; i++){
        ans = min(ans,l[i]+r[n-i-1]);
    }
    cout << ans << endl;

    return 0;
}