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

  string alp = "IVXLCDM";
  int num[7] = {1, 5, 10, 50, 100, 500, 1000};

  string s;
  while(cin >> s){
    reverse(s.begin(), s.end());
    int n = 0;
    int b = 0;
    for(int i=0; i<s.size(); i++){
      for(int j=0; j<7; j++){
        if( s[i] == alp[j] ){
          // cerr << n << " " << b << endl;
          if( num[j] < b ) n -= num[j];
          else n += num[j];

          b = num[j];
        }
      }

    }
    cout << n << endl;

  }

  return 0;
}

// EOF