#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    int m,n,o;
    cin>>a>>b>>c;
    m=a;
    n=b;
    o=c;

    b=m;
    a=o;
    c=n;

    cout<<a<<" "<<b<<" "<<c;
    return 0;
}
