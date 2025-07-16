#include<bits/stdc++.h>

constexpr auto MAXN = 1000000+500;

std::string s,t;
std::queue<int> que;

signed main(void)
{
  int len,down,up; size_t ans = 0;

  std::cin>>len>>s>>t;

  if(s == t){ puts("0"); return 0; }
  
  down = up = len-1;

  while(down >= 0){
    while(down && t[down-1]==t[down]) --down;
    while(up>=0 && (up>down || s[up]!=t[down])) --up;
    if(up < 0){ puts("-1"); return 0; }

    while(!que.empty() && que.front()-que.size() >= down) que.pop();
    if(up != down) que.push(up);
    ans = std::max(ans,que.size()+1);
    --down;
  }

  std::cout<<ans<<std::endl;
  
  return 0;
}
