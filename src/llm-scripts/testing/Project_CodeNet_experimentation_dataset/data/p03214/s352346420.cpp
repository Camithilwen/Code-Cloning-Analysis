#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
int T[105]={0};
int main(){
  int n;cin>>n;int sum=0;
  for(int i=0;i<n;i++){
    int k;cin>>k;
    sum+=k;
    T[i]=n*k;
  }
  int dif=1000000000;
  int ans=0;
  for(int i=0;i<n;i++){
    if(abs(sum-T[i])<dif){ans=i;dif=abs(sum-T[i]);}
  }
  cout<<ans<<endl;
}
