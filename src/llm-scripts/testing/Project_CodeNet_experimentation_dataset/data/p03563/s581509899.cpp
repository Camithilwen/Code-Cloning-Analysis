#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  vector<int > p(2);
  rep(i,2){cin >> p[i];}
  
  cout << p[1] + (p[1]-p[0]) << endl;
                  
}