
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    if(a=='R'&&b=='R'&&c=='R')
        ans = 3;
    else if((a=='R' && b=='R')|| (b=='R'&&c=='R'))
        ans= 2;
    else if(a=='R'||b=='R'||c=='R')
        ans =1;
    cout<<ans;
    return 0;
}
