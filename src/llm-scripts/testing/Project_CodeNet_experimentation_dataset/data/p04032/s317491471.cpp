#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000007
typedef long long int lint;

int main() {
  string S;
  cin >> S;
  int ans=0;
  bool fin = false;
  rep(i,0,S.size() - 1){
    if(S[i] == S[i + 1]){
      cout << i + 1 << " " << i + 2 << endl; 
      fin = true; 
      break;
    }
  }
  if(fin == false){
    rep(i,0,S.size() - 2){
      if(S[i] == S[i + 2]){
        cout << i + 1 << " " << i + 3 << endl; 
        fin = true; 
        break;
      }
    }
    if(fin == false){cout << -1 << " " << -1 << endl;}
  }
}