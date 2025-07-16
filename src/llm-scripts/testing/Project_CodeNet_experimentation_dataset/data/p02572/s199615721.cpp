#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  long long sum=0;
  for(int i=0;i<n;i++){
    sum=(sum+a.at(i))%1000000007;
  }
  long long ans=0;
  ans=(sum*sum)%1000000007;
  for(int i=0;i<n;i++){
    ans=(ans-(a.at(i)*a.at(i))%1000000007)%1000000007;
  }
  if(ans<0){
    ans=1000000007+ans;
  }
  ans=((ans*1000000008)/2)%1000000007;
  cout<<ans;
}