#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;


void solve(long long H, long long W, long long A, long long B){
  rep(i,H-B) {
    rep(j,W-A) {
      std::cout << 1;
    }
    rep(j,A) {
      std::cout << 0;
    }
    std::cout << std::endl;
  }
  rep(i,B) {
    rep(j,W-A) std::cout << 0;
    rep(j,A) std::cout << 1;
    std::cout << std::endl;
  }
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(H, W, A, B);
    return 0;
}
