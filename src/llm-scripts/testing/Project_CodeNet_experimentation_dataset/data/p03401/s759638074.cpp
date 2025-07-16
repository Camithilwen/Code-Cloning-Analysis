#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<int> X(N);
   for(int i=0;i<N;i++){
      cin>>X[i];
   }
   int sum=0;
   for(int i=0;i<N-1;i++){
      sum+=abs(X[i+1]-X[i]);
   }
   for(int i=0;i<N;i++){
      if(i==N-1){
         cout<<sum+abs(X[0])+abs(X[N-2])-abs(X[i]-X[i-1])<<endl;
      }else if(i==0){
         cout<<sum+abs(X[1])+abs(X[N-1])-abs(X[1]-X[0])<<endl;
      }else{
         cout<<sum+abs(X[0])+abs(X[N-1])+abs(X[i+1]-X[i-1])-abs(X[i+1]-X[i])-abs(X[i]-X[i-1])<<endl;
      }
   }
   return 0;
}