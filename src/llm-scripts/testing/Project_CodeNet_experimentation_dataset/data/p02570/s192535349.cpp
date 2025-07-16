#include<iostream>
#include<stdio.h>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod=1000000007;


int main(){
  int d,t,s;
  cin>>d>>t>>s;
  
if(d-t*s<=0)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}