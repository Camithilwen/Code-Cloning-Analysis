#include<iostream>
using namespace std;
int main ()
{
    int a,b;
    int m,n,j,k;
    cin>>a>>b;
    m=a+(a-1);
    n=b+(b-1);
    k=a+b;
    if( m>n && m>k)
        cout<<m<<endl;
    else if (n>m &&n>k)
        cout<<n<<endl;
    else
        cout<<k<<endl;
    return 0;
}




