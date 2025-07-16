#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define MOD 1000000007
int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<long long int> l,r;
  int parity = 0;
  for(int i=0;i< 2*n;i++){
    if(parity < 0){cout << 0 << endl; return 0;}
    if(parity==0 && s[i]=='W'){cout << 0 << endl; return 0;}
    if((parity%2==1) == (s[i]=='W')) {parity++; l.push_back(i);}
    else {parity--; r.push_back(i);}
  }
  if(parity != 0 || (r.size() != n) || (l.size()!=n) ){cout << 0 << endl; return 0;}
  long long int ans = 1;
  for(int i=n-1; i>=0; i--){
  	int num = n - (n-1-i) - (lower_bound(r.begin(), r.end(), l[i]) - r.begin());
    ans = (ans * num) % MOD;
  }
  for(int i=1;i<=n;i++){
    ans = (ans * i) % MOD;
  }
  cout << ans << endl;
  return 0;
}