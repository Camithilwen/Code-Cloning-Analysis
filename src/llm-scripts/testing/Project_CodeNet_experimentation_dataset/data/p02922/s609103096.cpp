#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int a,b;
  cin>>a>>b;
  int counter=1;
  int cnt=0;
 while(counter<b){
  counter--; 
 counter+=a;
 cnt++;
 }
  cout<<cnt<<endl;
}