#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  vector<int> arr(N);
  for(int i=0;i<N;i++){
    int num=0;
    while(vec.at(i)%2==0){
      vec.at(i) = vec.at(i)/2;
      num+=1;
    }
    arr.at(i)=num;
  }
  int ans=arr.at(0);
  for(int i=1;i<N;i++){
    ans = min(ans, arr.at(i));
  }
  cout<<ans<<endl;
}