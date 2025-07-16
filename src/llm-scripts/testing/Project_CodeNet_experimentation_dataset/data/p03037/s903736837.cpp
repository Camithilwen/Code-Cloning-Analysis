#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  int arr[N+1];
  for(int i=0;i<=N;++i) arr[i] = 0;
  int L, R;
  for(int i=0;i<M;++i) {
    cin>>L>>R;
    L--;
    arr[L]++;
    arr[R]--;
  }
  for(int i=1;i<=N;++i) arr[i] += arr[i-1];
  int ans = 0;
  for(int i=0;i<=N;++i) {
    if(arr[i]==M) ans++;
  }
  cout<<ans<<endl;
}

