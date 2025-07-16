#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ks(int n){
  int ans=1;
  for(int i=0;i<n;i++){
    ans*=10;
  }
  return ans;
}

int ki(int n){
  if(n==1){
    return 0;
  }
  int ans=1;
  for(int i=0;i<n-1;i++){
    ans*=10;
  }
  return ans;
}

bool hantei(int N,int n,int s,int c){
  int ss=ks(N-s+1);
  int si=ks(N-s+1)/10;
  if(n%ss/si==c){
    return true;
  }
  return false;
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> s(M);
  vector<int> c(M);
  for(int i=0;i<M;i++){
    cin >> s[i] >> c[i];
  }
  for(int i=ki(N);i<ks(N);i++){
    int flag=0;
    for(int j=0;j<M;j++){
      if(!hantei(N,i,s[j],c[j])){
        flag=1;
      }
    }
    if(flag==1){
      continue;
    }
    else{
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}