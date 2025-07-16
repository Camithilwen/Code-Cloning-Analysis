#include<bits/stdc++.h>
using namespace std;

int main() {

  int n;
  while( cin >> n, n ) {
    for(int i=0; i<n; i++) {
      int pm, pe, pj;
      cin >> pm >> pe >> pj;
      int ave = (pm + pe + pj) / 3;
      
      if( pm == 100 || pe == 100 || pj == 100 ) cout << 'A' << endl;
      else if( (pm + pe) / 2 >= 90 ) cout << 'A' << endl;
      else if( ave >= 80 ) cout << 'A' << endl;
      else if( ave >= 70 ) cout << 'B' << endl;
      else if( ave >= 50 && ( pm >= 80 || pe >= 80 ) ) cout << 'B' << endl;
      else cout << 'C' << endl;
    }
  }
}