#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>in(n);
  rep(i,n*(n-1)/2){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;b--;
    if(c==d){in[a]++;in[b]++;}
    else if(c>d)in[a]+=3;
    else in[b]+=3;
  }
  //rep(i,n)cout<<in[i]<<endl;
  int num=1;
  vector<int>out(n);
  while(1){
    int maxi=-1;
    rep(i,n)if(!out[i])maxi=max(maxi,in[i]);
    if(maxi==-1)break;
    int co=0;
    rep(i,n)if(maxi==in[i]){co++;out[i]=num;in[i]=-2;}
    num+=co;
  }
  rep(i,n)cout<<out[i]<<endl;
}