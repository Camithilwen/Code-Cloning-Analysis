#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a=a+b;
    c=c+d;
    if(a>c)
    {
        cout<<"Left";
    }
    else if(a==c)
        cout<<"Balanced";
    else
        cout<<"Right";
    return 0;
}
