#include <bits/stdc++.h> 
using namespace std;

int main(){
   int x;
   cin>>x;
   int ans,count,s;
   ans=x%500;
   count=ans%5;
   s=(x-ans)/500*1000+(ans-count)/5*5;
   cout<<s<<endl;
}