#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int , int> ii;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int N;
string S;
ll fac[maxn];

int main(){
  cin >> N;
  cin >> S;
  fac[0] = 1;
  for(int i = 1; i < maxn; ++i)fac[i] = fac[i - 1] * i % mod;
  ll ret = 1;
  ll cnt = 0;
  for(int i = 0; i < 2 * N; ++i){
    char cc;
    if(cnt & 1){
      if(S[i] == 'W'){
        cc = 'L';
      }
      else{
        cc = 'R';
      }
    }
    else{
      if(S[i] == 'W'){
        cc = 'R';
      }
      else{
        cc = 'L';
      }
    }
    if(cc == 'R'){
      ret = (ret * cnt) % mod;
      --cnt;
    }
    else ++cnt;
    if(cnt < 0){
      cout << 0 << endl;
      return 0;
    }
  }
  if(cnt)cout << 0 << endl;
  else cout << (ret * fac[N] % mod + mod) % mod << endl;
  return 0;
}
