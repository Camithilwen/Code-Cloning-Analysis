
#include <bits/stdc++.h>
using namespace std;
vector<int> prime(0);
const int M=1000;

void primeGeneration(){
  vector<bool> number(M,true);
  for(int i=2;i*i<M;i++){
    for(int j=i+i;j<=M;j+=i){
      number[j]=false;
    }
  }
  for(int i=2;i<M;i++){
    if(number[i])prime.push_back(i);
  }
};

void factorization(vector<int> &num,vector<int> &pow,int N){
  int n=0,k=-1;
  int rn=-1;
  for(int i=0;i<M;i++){
    num[i]=0;pow[i]==0;
  }
  while(true){
    if(N%prime[n]==0){
      if(rn!=n){
        k++;
        num[k]=prime[n];
      }
      pow[k]++;
      N/=prime[n];
      rn=n;
    }else{
      n++;
    }
    if(N==1)break;
    if(prime[n]*prime[n]>N){
      bool ne=true;
      for(int i=0;i<=k;i++){
        if(num[i]==N){
          pow[i]++;
          ne=false;
          break;
        }
      }
      if(ne){
        num[k+1]=N;
        pow[k+1]=1;
      }
      break;
    }
  }
};

int main() {
  primeGeneration();
  //for(int i=0;i<M;i++)cout<<prime[i]<<endl;
  int N;cin>>N;
  vector<int> pow(M,0);
  for(int i=2;i<=N;i++){
    vector<int> p(M,0);
    vector<int> n(M,0);
    factorization(n,p,i);
    int k=0;
    for(int j=0;j<prime.size();j++){
      //cout<<prime[j]<<" "<<n[k]<<endl;
      if(prime[j]==n[k]){
        pow[j]+=p[k];k++;
      }
    }
  }
  long cnt=1;
  for(int i=0;i<M;i++){
    cnt=(cnt*(pow[i]+1))%1000000007;
  }
  cout<<cnt<<endl;
}
