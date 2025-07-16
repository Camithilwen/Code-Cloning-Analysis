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
#include <math.h>
using namespace std;



int main(void){
  int N,Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> ac(S.size(),0);
  int cnt = 0;
  for(int i =1; i <= S.size(); i++){
    if(S[i-1] == 'A' && S[i] == 'C'){
      cnt++;
    }
    ac[i] = cnt;
  }
  for(int i = 0; i < Q; i++){
    int l, r;
    cin >> l >> r;
    cout << ac[r-1] - ac[l-1] << endl;
  }
  return 0;
}