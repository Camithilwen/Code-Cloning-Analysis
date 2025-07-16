#include<bits/stdc++.h>
using namespace std;
int main()
{  int a,b;
   cin>>a>>b;
   int r=abs(a-b);
  int k=0; 
 if(a<b) 
     k=2*a+2*r;
 else
     k=2*b+2*r;
if(k<=16)
  cout<<"Yay!";
else
  cout<<":(";
}