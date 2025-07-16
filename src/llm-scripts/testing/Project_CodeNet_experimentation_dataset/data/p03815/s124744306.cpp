#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <math.h>
#include <list>
using namespace std;

int main(void){
  long x;
  cin >> x;
  long neko = x / 11;
  long amari = x % 11;
  cout << neko*2 + ((amari == 0) ? 0 :((amari > 6)? 2 : 1 ))<< endl;
  return 0;
}