#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<char> S(N);
   for(int i=0;i<N;i++){
      cin>>S[i];
   }
   int ans=0;
   vector<int> E(N+1);
   vector<int> W(N+1);
   E[0]=0;
   W[0]=0;
   for(int i=0;i<N;i++){
      if(S[i]=='E'){
         E[i+1]=E[i]+1;
      }else{
         E[i+1]=E[i];
      }
      if(S[i]=='W'){
         W[i+1]=W[i]+1;
      }else{
         W[i+1]=W[i];
      }
   }
   ans=N;
   for(int i=0;i<N;i++){
      int result=W[i+1]+E[N]-E[i]-1;
      ans=min(result,ans);
   }
   cout<<ans<<endl;
   return 0;
}