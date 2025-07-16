#include <iostream>
#include<cmath>
using namespace std;

int main()
{
int N,X,T;
cin>>N>>X>>T;
int k=ceil((double)N/X);
int val=k*T;
cout<<val<<endl;
    return 0;
}
