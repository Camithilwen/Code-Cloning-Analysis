#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0; i < N; i++)

int main()
{
  string s;
  int maxv = 0;
  int m[3] = {'J','O','I'};

  cin >> s;
  int i = 0;
  while(i < s.size()) {
    if(m[0] == s[i]) {
      int count[3] = {0};
      Rep(j,3)for(; m[j] == s[i]; i++, count[j]++);
      if(min(count[0],count[2]) < count[1])continue;
      maxv = max(maxv,count[1]);
    } else i++;
  }
  cout << maxv << endl;
  return 0;
}