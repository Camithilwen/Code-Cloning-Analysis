#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
   int n,l;
   cin>>n;
   vector<int>v;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int d=a[0];
   int c=0;
   for(int i=0;i<n;i++){
      if(a[i]<=d){
        c++;
        v.push_back(a[i]);
        d=a[i];
      }
    }
     cout<<c<<endl;
    return 0;
}
