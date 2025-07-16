#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,count=0;
  cin>>N;
  vector<long long> A(N);
  unordered_map<long long,long long> mp;
  for(int i=0;i<N;i++){
    cin>>A.at(i); 
    mp[A.at(i)]++;
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  for(int i=0;i<N;i++){
    if(mp[A.at(i)]>=4){
      if(count==0){
        cout<<A.at(i)*A.at(i)<<endl;
        return 0;
      }
      if(count>0){
        cout<<count*A.at(i)<<endl;
        return 0;
      }
    }
    if(mp[A.at(i)]>=2){
      if(count==0){
        count=A.at(i);
        mp[A.at(i)]=0;
      }
      else{
        cout<<count*A.at(i)<<endl;
        return 0;
      }
    }
  }
  cout<<0<<endl;
}