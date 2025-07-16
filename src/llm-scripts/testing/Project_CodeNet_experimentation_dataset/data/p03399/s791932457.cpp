#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if(a>b)
    {
        e=a;
        a=b;
        b=e;
    }
    if(c>d)
    {
        e=c;
        c=d;
        d=e;
    }
       cout<<(a+c);

    return 0;
}
