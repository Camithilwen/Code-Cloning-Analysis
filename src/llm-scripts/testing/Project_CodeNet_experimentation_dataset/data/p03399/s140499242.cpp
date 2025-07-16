#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,ans;
    while(cin >> a >> b >> c >> d){
        ans = 0;
        ans+=min(a,b);
        ans+=min(c,d);
        cout << ans << endl;
    }
}
