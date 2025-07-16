#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  map<int ,bool> AC;
  map<int ,int> WA;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int no;
    string res;   
    cin >> no >> res;
    if (res == "AC") {
      AC[no] = 1;
    } else {
      if (!AC.count(no)) {
        WA[no]++;
      }
    }
  }
  int ac, wa;
  ac = wa = 0;
  for(auto m: AC){
    int p;
    p = m.second;
    ac += p;
  }
  for(auto m: WA){
    if (AC[m.first] == 1) {
      wa += m.second;
    }
  }
  cout << ac << " " << wa << endl;
}