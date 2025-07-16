#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
    int a,b,ans,pl;
    cin >> a >> b;
    pl=1;
    for(ans=0;pl<b;ans++){
        pl += a-1;
    }
    cout << ans << endl;
}