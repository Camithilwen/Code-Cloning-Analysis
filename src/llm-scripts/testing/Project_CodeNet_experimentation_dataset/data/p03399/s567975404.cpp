#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,sum;
     cin>>a>>b>>c>>d;
     if(a>b && c>d)
        sum=b+d;
     else if(a>=b && c<=d)
        sum=b+c;
        else if(a<=b && c<=d)
        sum=a+c;
        else if(a<=b && c>=d)
        sum=a+d;
         cout<<sum<<endl;

    return 0;
}
