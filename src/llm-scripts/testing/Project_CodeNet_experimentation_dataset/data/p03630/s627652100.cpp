#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define re(c, b) for(ll c=0;c<b;c++)
using namespace std;

int main() {
  int h, w;scanf("%d %d", &h, &w);
  vector<string> s(h);
  for(int i=0;i<h;i++) std::cin >> s[i];
  vector<set<int>> spl(w);
  for(int i=w-1;i>=1;i--){
    int mode = (s[0][i]==s[0][i-1]);
    for(int j=1;j<h;j++){
      if(mode==(s[j][i]==s[j][i-1])) continue;
      mode = (s[j][i]==s[j][i-1]);
      spl[i].insert(j-1);
    }
  }

  vector<int> las(h, -1);
  int ans = 0;
  for(int j=w-1;j>=0;j--){
    int tmp = h;
    map<int, int> L;
    map<int, int> rev; // 長さ、個数
    L.emplace(0, h);
    rev.emplace(h, 1);

    for(int i=1;i+j<w;i++){
      for(auto t:spl[i+j]){
        auto itr = --L.upper_bound(t);
        int x_len = t - (*itr).first + 1;
        int y_len = (*itr).first + (*itr).second - 1 - t;

        auto x = rev.find((*itr).second);
        if((*x).second==1) rev.erase(x);
        else (*x).second--;

        (*itr).second = x_len;
        L.emplace(t+1, y_len);

        x = rev.find(x_len);
        if(x==rev.end()) rev.emplace(x_len, 1);
        else (*x).second++;

        x = rev.find(y_len);
        if(x==rev.end()) rev.emplace(y_len, 1);
        else (*x).second++;
        //rev.insert(x_len);
        //rev.insert(y_len);
      }
      auto itr = (--rev.end());
      tmp = max((*itr).first*(i+1), tmp);
    }
    ans = max(ans, tmp);
    for(auto i:spl[j]){
      if(las[i]!=-1) spl[las[i]].erase(i);
      las[i] = j;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
