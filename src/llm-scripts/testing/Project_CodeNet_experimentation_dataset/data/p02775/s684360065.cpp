#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 998244353
#define INIT -1

int main()
{
   string n;
   cin >> n;
   // result[i][0] : i - 1桁めまで払ってる　繰り下がりはない
   // result[i][1] : i - 1桁目まで払ってる　繰り下がりあり
   int result[1000010][2] = {};
   result[0][0] = 0;
   result[0][1] = 1;
   for (int i = 1; i <= n.length(); i++)
   {
      result[i][0] = min(result[i - 1][0] + (n[i - 1] - '0'), result[i - 1][1] + (10 - (n[i - 1] - '0')));
      result[i][1] = min(result[i - 1][1] + (10 - (n[i - 1] - '0') - 1), result[i - 1][0] + (n[i - 1] - '0' + 1));
   }
   cout << result[n.length()][0] << endl;
}