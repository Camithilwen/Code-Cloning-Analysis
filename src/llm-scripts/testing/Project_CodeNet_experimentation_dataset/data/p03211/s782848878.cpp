#include <bits/stdc++.h>
using namespace std;  

int main(){
    string s;
    int ans, t;
    
    cin >> s;
    ans = 1000;
    for ( int i = 2;i < s.size(); i++ ) {
        t = (s[i-2] - '0') * 100 + (s[i-1] - '0') * 10 + s[i] - '0';
        
        ans = min(ans, abs(t-753));
    }
    cout << ans << endl;
    
    return (0);
}