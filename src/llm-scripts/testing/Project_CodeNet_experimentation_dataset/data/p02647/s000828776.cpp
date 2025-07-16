#include <iostream>
#include <vector>
using namespace std;

int n, k;
bool alln(vector<int>& v){
  for(int i=0;i<n;++i) if(v[i]!=n) return false;
  return true;
}

void simulate(vector<int>& v){
  int cnt = 0;
  vector<int> tmp(n+1, 0);
  for(int i=0;i<n;++i) {
    tmp[max(0, i-v[i])]++;
    tmp[min(n, i+v[i]+1)]--;
  }
  for(int i=0;i<n;++i){
    cnt += tmp[i];
    v[i] = cnt;
  }
}

int main() {
  scanf("%d %d", &n, &k);
  vector<int> v(n);
  for(int i=0;i<n;++i) scanf("%d", &v[i]);

  while(k--){
    simulate(v);
    if(alln(v)){
      for(int i=0;i<n;++i) cout << n << (i==n-1?'\n':' ');
      return 0;
    }
  }
  for(int i=0;i<n;++i) cout << v[i] << (i==n-1?'\n':' ');
  return 0;
}
