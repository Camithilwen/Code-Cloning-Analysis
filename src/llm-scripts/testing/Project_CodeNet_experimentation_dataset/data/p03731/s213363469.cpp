#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,t;
  cin>>n>>t;
  int sum=0;
  int cur=0;
  rep(i,0,n){
    int a;
    cin>>a;
    if(cur<=a){
      sum+=t;
    }
    else{
      sum+=a+t-cur;
    }
    cur=a+t;
  }
  cout<<sum<<endl;
}