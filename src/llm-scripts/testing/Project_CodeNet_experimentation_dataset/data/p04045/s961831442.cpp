#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int jd(vi D, int N){
  while(N > 0){
    for(int x : D){
      if (N%10 == x ){
        return 0;
      }
    }
    N /= 10;
  } 
  return 1;
}


int main() {
  int N, K; cin >> N >> K;
  vi D(K); rep(i,K) cin >> D[i];
  int ans=0;
  while(ans <= 0){
    ans = jd(D, N);
    if(ans==0) N++;
  }  
  cout << N << endl;
}
