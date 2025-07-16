#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1<<17;

int n,dat[2*MAX_N-1];

//?????????
void init(int n_){
  //????´???°n???2???????????????
  n=1;
  while(n<n_)n*=2;
  for(int i=0;i<2*n-1;i++)dat[i]=INT_MAX;
}

void update(int a,int b,int k,int l,int r,int x){
  if(r<=a||b<=l)return;
  if(a<=l&&r<=b)dat[k]=x;
  else{
    if(dat[k]!=INT_MAX){
      dat[k*2+1]=dat[k];
      dat[k*2+2]=dat[k];
      dat[k]=INT_MAX;
    }
    update(a,b,k*2+1,l,(l+r)/2,x);
    update(a,b,k*2+2,(l+r)/2,r,x);
  }
}

int find(int a,int b,int k,int l,int r){
  if(r<=a||b<=l)return INT_MAX;
  if(a<=l&&r<=b)return dat[k];
  else{
    if(dat[k]!=INT_MAX){
      dat[k*2+1]=dat[k];
      dat[k*2+2]=dat[k];
      dat[k]=INT_MAX;
    }
    return min(find(a,b,k*2+1,l,(l+r)/2),find(a,b,k*2+2,(l+r)/2,r));
  }
}

int main(){
  int q;
  cin>>n>>q;
  
  init(n);
  int u,s,t,x;
  for(int i=0;i<q;i++){
    cin>>u;
    if(!u){
      cin>>s>>t>>x;
      update(s,t+1,0,0,n,x);
    }else{
      cin>>s;
      cout<<find(s,s+1,0,0,n)<<endl;
    }
  }
  
  return 0;
}