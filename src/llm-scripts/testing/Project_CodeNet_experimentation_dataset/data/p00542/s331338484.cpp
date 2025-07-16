#include <iostream>
#include <deque>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n;
int ans=0;
typedef vector<int> vi;
int main()
{
  vi a(4,0);
  vi b(2,0);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  cin >> b[0] >> b[1];
  sort(a.begin(),a.end(),greater<int>());
  sort(b.begin(),b.end(),greater<int>());
  int ans=0;
  for(int i=0;i<3;i++)
    {
      ans+=a[i];
    }
  ans+=b[0];
  cout << ans << endl;
  return 0;
}

