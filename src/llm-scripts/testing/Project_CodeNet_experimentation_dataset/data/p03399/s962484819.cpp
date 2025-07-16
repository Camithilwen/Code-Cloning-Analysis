
#include<bits/stdc++.h>
using namespace std;

int main(){
 int a,b,c,d;
 cin>>a>>b>>c>>d;
 
 int sum1=min(a,b);
 int sum2=min(c,d);
  
 int sum=sum1+sum2;
 cout<<sum<<endl;

return 0;
}