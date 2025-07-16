#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
  string ss;
  cin >> ss;
  if(ss[0] != 'A')
  {
    cout << "WA" << endl;
    return 0;
  }
  int64 cc = 0;
  for(int64 ii = 2;ii < ss.length() - 1;ii++)
  {
    if(ss[ii] == 'C')
    {
      cc++;
    }
  }
  if(cc != 1)
  {
    cout << "WA" << endl;
    return 0;
  }
  cc = 0;
  for(int64 ii = 0;ii < ss.length();ii++)
  {
    if(ss[ii] >= 'A' && ss[ii] <= 'Z')
    {
      cc++;
    }
  }
  if(cc != 2)
  {
    cout << "WA" << endl;
    return 0;
  }
  cout << "AC" << endl;
  return 0;
}
