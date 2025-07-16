#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b,c;
    int x,y;
    cin>>a>>b>>c;
    x=a.size();
    y=b.size();
    if(a[x-1]==b[0] && b[y-1]==c[0])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
