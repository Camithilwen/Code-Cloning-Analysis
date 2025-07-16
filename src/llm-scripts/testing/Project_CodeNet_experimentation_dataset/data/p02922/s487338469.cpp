#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  int n=1;
  int cnt=0;

  cin >> a >> b;
  if(n<b)
  {
    n=a, cnt++;
  }
  while(n<b)
  {
    n+=a-1;
    cnt++;
  }

  cout << cnt << endl;
}