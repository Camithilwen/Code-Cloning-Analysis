#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define PI 3.1415926535897932
#define MOD 1000000007;
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
long long LCM(long long A,long long B){
  long long g=GCD(A,B);
  return A/g*B;
}
long long num_order(long long X){
  long long ans=0;
  while(true){
    if(X==0){
      break;
    }
    else{
      X/=10;
      ans++;
    }
  }
  return ans;
}

vector<pair<long long,long long>> prime_factorize(long long N){
  vector<pair<long long,long long>> res;
  
  for(long long i=2;i*i<=N;i++){
    if(N%i!=0){
    continue;
    }
    
    long long ex=0;
    while(N%i==0){
      ex++;
      N/=i;
    }
    
    res.push_back({i,ex});
  }
  
  if(N!=1){
  res.push_back({N,1});
  }
  
  return res;
}


int main() {
  
  int N;
  cin>>N;
  
  vector<vector<int>> vec(N,vector<int>(2));
  for(int i=0;i<N;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
  
  vector<int> root(N);
  for(int i=0;i<N;i++){
    root[i]=i;
  }
  
  double sum=0;
  
  
  do{
    double d=0;
    for(int i=0;i<N-1;i++){
      double a=pow((vec[root[i]][0]-vec[root[i+1]][0]),2);
      double b=pow((vec[root[i]][1]-vec[root[i+1]][1]),2);
      d+=pow(a+b,0.5);
    }
    sum+=d;
  }
  while(next_permutation(root.begin(),root.end()));
  
  
  int x=1;
  for(int i=2;i<=N;i++){
    x*=i;
  }
  
  
  cout<<fixed<<setprecision(10)<<sum/x<<endl;
}