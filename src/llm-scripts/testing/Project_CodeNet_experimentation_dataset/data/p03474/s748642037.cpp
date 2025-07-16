#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int a, b;
   string s;
   cin >> a >> b >> s;
   if(a+b+1 != s.size() || s[a] != '-')
   {
      cout << "No" << nl;
      return 0;
   }
   for(int i = 0; i < s.size(); i++)
   {
      if(i == a) continue;
      if(s[i] < '0' || s[i] > '9')
      {
         cout << "No" << nl;
         return 0;
      }
   }
   cout << "Yes" << nl;
   return 0;
   return 0;
}
