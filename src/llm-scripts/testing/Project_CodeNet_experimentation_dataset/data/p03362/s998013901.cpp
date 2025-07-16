#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define mod 1000000007

vector<bool> prime(1000001,1);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int i=2;i*i<=1000000;i++)
    if(prime[i])
      for(int j=i*2;j<=1000000;j+=i)
        prime[j]=0;

  int n; cin>>n;
  vector<int> ans; int p=11;
  while(ans.size()<n){
    if(prime[p]&&(p%5==1))
      ans.eb(p);
    p++;
  }

  for(auto i:ans)
    cout<<i<<" ";
  cout<<"\n";
  return 0;
}