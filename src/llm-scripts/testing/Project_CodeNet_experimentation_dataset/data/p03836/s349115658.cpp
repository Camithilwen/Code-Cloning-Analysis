#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int x=c-a,y=d-b;
  for(int i=0;i<x;i++)cout<<'R';
  for(int i=0;i<y;i++)cout<<'U';
  for(int i=0;i<x;i++)cout<<'L';
  for(int i=0;i<y;i++)cout<<'D';
  cout<<'D';
  for(int i=0;i<x+1;i++)cout<<'R';
  for(int i=0;i<y+1;i++)cout<<'U';
  cout<<"LU";
  for(int i=0;i<x+1;i++)cout<<'L';
  for(int i=0;i<y+1;i++)cout<<'D';
  cout<<"R\n";
}