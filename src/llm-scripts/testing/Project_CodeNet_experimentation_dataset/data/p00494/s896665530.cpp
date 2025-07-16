#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define INF (2 << 28)
#define fr first
#define sc second
using namespace std;

typedef long long ll;
typedef pair<int, int> iP;

int main(){
  
  string s;
  int kmax = 0;

  cin >> s;
  
  for(int i = 0; i < s.size(); i++){
    bool j1, j2;
    int cnt = 0;
    if(s[i] == 'O'){
      j1 = false, j2 = false;
      cnt = 1;
      for(int j = i + 1; s[j] == 'O' && j < s.size(); j++) cnt++;
      for(int j = i - 1, c = 1; s[j] == 'J' && j >= 0; j--, c++){
        if(c == cnt){
          j1 = true;
          break;
        }
      }
      for(int j = i + cnt, c = 1; s[j] == 'I' && j < s.size(); j++, c++){
        if(c == cnt){
          j2 = true;
          break;
        }
      }
    }
    if(j1 && j2) kmax = max(kmax, cnt);
    i += cnt;
  }
  
  cout << kmax << endl;
      
}