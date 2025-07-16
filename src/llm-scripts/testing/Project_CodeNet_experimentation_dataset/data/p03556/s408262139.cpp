#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int64_t i=1;i<n;++i){
    if(i*i>n){
      cout<<(i-1)*(i-1)<<endl;
      return 0;
    }
  }
  cout<<1<<endl;
}