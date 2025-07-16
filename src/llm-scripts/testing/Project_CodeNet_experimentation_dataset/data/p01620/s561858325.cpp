#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define PI acos(-1)

typedef long long ll;

#define MAX_N 100

int n;
int k[MAX_N];
string s;
string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<string> ans_list;

int main(){

  while(true){
    cin >> n;
    if(n == 0)
      break;
    for(int i = 0; i < n; i++){
      cin >> k[i];
    }
    cin >> s;
    string ans;
    int num = 0;
    for(int i = 0; i < s.length(); i++, num++){
      if(num == n)
	num = 0;
      int tmp;
      for(tmp = 0; tmp < 52; tmp++){
	if(str[tmp] == s[i])
	  break;
      }
      tmp -= k[num];
      if(tmp < 0)
	tmp += 52;
      ans += str[tmp];
    }
    ans_list.push_back(ans);
  }

  for(int i = 0; i < ans_list.size(); i++){
    cout << ans_list[i] << endl;
  }

  return 0;

}