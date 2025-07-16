#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<double> p(N+1, 0);
  int x;
  double val;
  
  for(int i=1; i<=N; i++){
    cin >> x;
    val = x*(x+1) * 0.5 / x;
    p.at(i) = p.at(i-1) + val;
  }
  
  double maxi=0;
  for(int i=0; i<N-K+1; i++){
    maxi = max(maxi, p.at(K+i) - p.at(i)); 
  }
  printf("%.6f\n", maxi);
  return 0;
}