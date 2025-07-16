#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;
using lll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
  lll ii,jj,kk;
  vector<int> ret;
  int n;

  cin >> n;
  lll sum = 0;
  for(ii=1;ii<=n;ii++){
    if((ii % 3 == 0) &&
       (ii % 5 == 0)){

    }
    else if(ii % 3 == 0){

    }
    else if(ii % 5 == 0){

    }
    else{
      sum += ii;
    }

  }

  cout << sum << endl;
  
  return 0;
}
