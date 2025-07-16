#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  string ans="AC";

  if(S.at(0)!='A') ans="WA";
  if('A'<=S.at(1) && S.at(1)<='Z') ans="WA";
  int count_C=0;
  for(int i=2;i<S.size()-1;++i){
    if('A'<=S.at(i) && S.at(i)<='Z'){
      if(S.at(i)!='C'){
	ans="WA";
	break;
      }
      else{
	if(count_C==0) ++count_C;
	else{
	  ans="WA";
	  break;
	}
      }
    }
  }
  if('A'<=S.at(S.size()-1) && S.at(S.size()-1)<='Z') ans="WA";
  if(count_C!=1) ans="WA";

  cout << ans << endl;

  return 0;
}
