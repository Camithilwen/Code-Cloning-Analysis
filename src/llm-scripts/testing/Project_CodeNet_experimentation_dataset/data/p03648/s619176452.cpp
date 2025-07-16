#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;


int main() {
  ll K;
  cin >> K;
  int N = 50;
  vll a(N,N-1);
  repeat(i,N){
    a[i] += K/N;
  }
  repeat(i,K%N){
    a[i] += N+1;
  }
  repeat(i,N){
    a[i] -= K%N;
  }
  cout << N << endl;
  repeat(i,N){
    cout << a[i];
    cout <<(i<N-1? " ":"\n");
  }
  return 0;
}
