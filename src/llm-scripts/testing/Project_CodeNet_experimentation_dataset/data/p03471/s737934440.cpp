#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main() {
  int N, Y;
  cin >> N >> Y;
  string ans="No";
  int fin=0;
  for (int i=0; i<=Y/10000; i++) {
    for (int j=0; j<=(Y-10000*i)/5000; j++) {
      if (Y-10000*i-5000*j==(N-i-j)*1000) {
        cout << i << " " << j << " " << N-i-j << endl;
        fin =1;
        break;
      }
    }
    if (fin==1) {break;}
  }
  if (fin==0) {
    cout << -1 << " " << -1 << " " << -1 << endl;
  }
}
 