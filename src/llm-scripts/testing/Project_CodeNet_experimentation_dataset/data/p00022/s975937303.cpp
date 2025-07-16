#include <iostream>
#include <vector>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
  
  int N;
  while(cin >> N && N) {
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    
    ll mx = -1<<29;
    rep(i, N) {
      ll sum = 0;
      REP(j, i, N) {
	sum += v[j];
	mx = max(mx, sum);
      }
    }
    cout << mx << endl;
  }
  
  return 0;
}