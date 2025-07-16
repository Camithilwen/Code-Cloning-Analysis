#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 2;

int main()
{
    int d, s, t;
    cin>>d>>t>>s;
    int time = (d + s - 1)/s;
    if(time <= t) cout<<"Yes\n";
    else cout<<"No\n";
}


