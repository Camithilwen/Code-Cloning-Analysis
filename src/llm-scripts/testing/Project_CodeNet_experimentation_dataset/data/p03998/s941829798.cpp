#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  string sa,sb,sc; cin >> sa >> sb >> sc;
  int a = 0, b = 0, c = 0;
  char now = 'a';
  char winner;
  while(true){
    if(now == 'a'){
      if(a == sa.size()){
        winner = 'A';
        break;
      }
      now = sa[a];
      a++;
    }else if(now == 'b'){
      if(b == sb.size()){
        winner = 'B';
        break;
      }
      now = sb[b];
      b++;
    }else if(now == 'c'){
      if(c == sc.size()){
        winner = 'C';
        break;
      }
      now = sc[c];
      c++;
    }
  }
  cout << winner;
  cout << "\n";
  return 0;
}
