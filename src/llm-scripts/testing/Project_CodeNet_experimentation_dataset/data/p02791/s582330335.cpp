#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  int N; cin >> N;
  vi P(N); rep(i,N) cin >> P[i];
  int count = 0;
  int minA = P[0];
  rep(i,N){
    if (P[i] <= minA) {count++; minA = P[i];}
  } 
  cout << count << endl;
  return 0;
}