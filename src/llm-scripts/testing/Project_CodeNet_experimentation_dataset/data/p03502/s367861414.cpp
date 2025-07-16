#include <bits/stdc++.h>
using namespace std;
int main (){
  int N,K,sum,s;
  cin>>N;
  K=1;
  sum=0;
  for (int i=0;i<8;i++){
    for(int j=0;j<i;j++){
      K*=10;
    }
    s=(N-N%K)%(K*10)/K;
    sum+=s;
    K=1;
  }
  int m;
  m=N%sum;
  if (m==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
