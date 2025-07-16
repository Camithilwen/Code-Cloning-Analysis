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
  int k,t;
  cin >> k >> t;
  vector<int> n(t);
  for(int i = 0;i < t;i++)cin >> n[i];
  sort(n.begin(),n.end());
  cout << max(0,n[t - 1] - (k - n[t - 1]) - 1) << endl;
}