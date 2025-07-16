#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  int h,w,n;
  cin>>h>>w>>n;
  if(w>h)swap(w,h);
  int ans=ceil((double)n/h);
  cout<<ans<<endl;
  
  
  


  return 0;
}
