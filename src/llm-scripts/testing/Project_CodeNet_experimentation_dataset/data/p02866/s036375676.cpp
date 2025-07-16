#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long D[100000],num[100000];
  int judge=0;
  for(int i=0;i<N;i++){
   cin>>D[i];
   num[i]=0;
  }
  if(D[0]==0){
  sort(D,D+N);
  for(int i=0;i<N;i++){
    if(judge==D[i]) judge++;
    num[D[i]]++;
  }
  if(judge!=D[N-1]+1||num[0]>1) cout<<0<<endl;
  else{
    long long answer=1;
    for(int i=1;i<judge;i++){
      for(int j=0;j<num[i];j++) answer=(answer*num[i-1])%998244353;
    }
    cout<<answer<<endl;
  }
  }
  else cout<<0<<endl;
  
  return 0;
}