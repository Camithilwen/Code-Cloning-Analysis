#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N;

int harshad(int n) {
  int ret=0;
  while(n>0) {
    ret+=n%10;
    n/=10;
  }
  return ret;
}

int main() {
  INCANT;
  cin >> N;
  string ans = N%harshad(N)==0?"Yes":"No";
  cout << ans << "\n";
  return 0;
}