#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int inf = 1000000000;

int main(void) {

  vector<int> l(10);
  vector<int> v(2);
  while( scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &l[0], &l[1], &l[2], &l[3], &l[4], &l[5], &l[6], &l[7], &l[8], &l[9], &v[0], &v[1])!= EOF ){
    int sum = accumulate(l.begin(), l.end(), 0);
    // cerr << sum << " ";
    double tmp = sum * v[0] * 1.0 / (v[0]+v[1]);
    // cerr << tmp << endl;
    for(int i=1; i<10; i++) l[i] += l[i-1];
    // int a = 0;
    for(int i=1; i<10; i++){
      if( l[i-1] == tmp ){
        cout << i << endl;
        break;
      }else if( l[i-1] < tmp && tmp < l[i] ){
        // cerr << l[i-1] << " " << l[i] << endl;
        cout << i+1 << endl;
        // break;
      }
    }
  }



  return 0;
}

// EOF