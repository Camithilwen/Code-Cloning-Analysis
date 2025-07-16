#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x;
    cin>>a>>b;
    c=max(a+b,a-b);
    x=max(c,a*b);
    cout<<x<<endl;


    return 0;
}
