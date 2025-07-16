#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  string s = to_string(n);
  ll wa = 0;
  for(int i = 0;i < (int)s.size();i++){
    wa += s[i] - '0';
  }
  if(n % wa == 0)cout << "Yes" << endl;
  else cout << "No" << endl;
}