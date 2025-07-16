#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  
  int ans = 1;
  for(int i=2;i*i<=N;i++){
    int work = i*i;
    ans = max(ans,work);
  }
  
  cout << ans << endl;
  
  return 0;
}