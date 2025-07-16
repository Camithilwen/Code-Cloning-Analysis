#include <iostream>

using namespace std;

int main()
{
    long long int s=0,r1,r2;
    cin>>r1>>r2;
    if(r1==1)
    s+=300000;
    if(r1==2)
    s+=200000;
    if(r1==3)
    s+=100000;
    if(r2==1)
    s+=300000;
    if(r2==2)
    s+=200000;
    if(r2==3)
    s+=100000;
    if(r1==1 &&r2==1)
    s+=400000;    
    
    cout<<s;
    
 
   return 0;
}
