#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
using namespace std;

int main(){
  int M[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string w[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

  int m, d;
  while( cin >> m >> d ){
    if( m == 0 || d == 0 ) break;

    int tmp = d;
    for(int i=0; i<m; i++) tmp += M[i];

    cout << w[tmp%7] << endl;
  }

  return 0;
}