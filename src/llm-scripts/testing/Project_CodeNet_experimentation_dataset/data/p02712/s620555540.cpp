#include<iostream>
#include<vector>
using namespace std;
int main(){
  long int n,sum=0;
  cin>>n;
  vector<int>v;
  for(long int i=1;i<=n;i++){
  
    v.push_back(i);
    if(i%3==0||i%5==0)
      v.pop_back();
  }

 
  for(long int i=0;i<v.size();i++){
    sum+=v[i];
  }
  cout<<sum;
  return 0;
}