#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> yakusu(int d){
  vector<int> res;
  for(int i=1; i*i <= d; i++){
    if(d % i == 0) {
      res.push_back(i);
      if(i*i != d) res.push_back(d / i);
    }
  }

  sort(res.begin(), res.end());

  return res;
}

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int gcd(int* a, int n){
  if(n == 2) return gcd(a[0], a[1]);
  int b[n-1];
  for(int i=0; i<n-1; i++){
    b[i] = gcd(a[i], a[i+1]);
  }
  return gcd(b, n-1);
}


int main(){
  int n; cin >> n;
  int a[n];
  for(int i=0; i<n; i++) cin >> a[i];

  int g = gcd(a, n);

  for(const auto& x : yakusu(g)){
    cout << x << endl;
  }

  return 0;
}

