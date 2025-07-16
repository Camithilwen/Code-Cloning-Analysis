#include<bits/stdc++.h>
#define N 10
using namespace std;
typedef long long ll;
int n,k,a[N];
set<ll> s;

int check(){
  int perm[N];
  for(int i=0;i<n;i++)perm[i]=i;
  do{
    ll num=0;
    for(int i=0;i<k;i++){
      if(!(a[perm[i]]/10))num=num*10+a[perm[i]];
      else num=num*100+a[perm[i]];
    }
    s.insert(num);
  }while(next_permutation(perm,perm+n));
  return s.size();
}

int main(){
  while(1){
    cin>>n>>k;
    if(!n&&!k)break;
    for(int i=0;i<n;i++)
      cin>>a[i];
    cout<<check()<<endl;
    s.clear();
  }
  return 0;
}