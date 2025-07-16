#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int>sumW(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i]=='W'){
      sumW[i+1]=sumW[i]+1;
    }
    else{
      sumW[i+1]=sumW[i];
    }
  }
  vector<int>sumE(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i]=='E'){
      sumE[i+1]=sumE[i]+1;
    }
    else{
      sumE[i+1]=sumE[i];
    }
  }
  int minn=1e9;
  for(int i=0;i<n+1;i++){
    minn=min(minn,(sumW[i]+sumE[n]-sumE[i]));
  }
  cout<<minn<<endl;
  
}