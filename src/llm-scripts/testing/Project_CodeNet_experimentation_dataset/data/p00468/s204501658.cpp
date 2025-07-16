#include <iostream>
#include <set>

using namespace std;

#define rep(i,a,b) for(int i=(a); i<(b); i++)

int main(){
  int m,n;
  while(cin >> n >> m, m + n){
    int p[10001][2];
    set<int> fri1;
    set<int> fri2;
    rep(i,0,m){
      int a,b; cin >> a >> b;
      p[i][0] = a;
      p[i][1] = b;
      if(a == 1 || b == 1){
        fri1.insert(a);
        fri1.insert(b);
      }
    }
    if(fri1.size() == 0){
      cout << 0 << endl;
      continue;
    }
    rep(i,0,m){
      if(fri1.find(p[i][0]) != fri1.end() || fri1.find(p[i][1]) != fri1.end()){
        fri2.insert(p[i][0]);
        fri2.insert(p[i][1]);
      }
    }
    cout << fri2.size()-1 << endl;
  }
  return 0;
}