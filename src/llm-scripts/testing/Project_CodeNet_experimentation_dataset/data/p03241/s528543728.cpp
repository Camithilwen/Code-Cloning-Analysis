#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N, M; cin >> N >> M;
  int MAX = M/N;
  for (int i=MAX;i>=1;i--){
    if ((M - i*N)%i==0) {
      cout << i << endl;
      return 0;
    }
  }
  

  // cout << fixed << setprecision(10);
  
  return 0;
}
