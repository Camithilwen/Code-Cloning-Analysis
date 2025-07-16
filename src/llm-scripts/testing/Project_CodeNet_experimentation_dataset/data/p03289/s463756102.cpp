#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;


#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define asd cout << "ok" << endl;


#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define trav(it, m) for(auto it = m.begin(); it!= m.end(); it++)

const int MOD = 1e9 + 7;
const ll INF = 1e19;
const ld PI = acos((ld)-1);
const int MX = 2e5 +5;
const char nl = '\n';


int main(){

  string s; cin >> s;
  int ok1 = 0, ok2 = 0, ok3 = 0;
  if(s[0] == 'A')
    ok1= 1;
  int cnt = 0;
  for(int i =2; i < s.size()-1; i++)
  {
    if(s[i] == 'C')
      cnt++;
  }
  if(cnt == 1)
    ok2 = 1;
  if(s[1] < 'a' || s[1] > 'z')
  {
    cout << "WA" <<nl;
    return 0;
  }
  if(s[s.size() -1] < 'a' || s[s.size()-1] > 'z')
  {
    cout << "WA" <<nl;
    return 0;
  }

  for(int i = 1; i < s.size(); i++)
  {
    if(s[i] >= 'a' && s[i] <= 'z' || s[i] == 'C')
      ok3 = 1;
  }
  if(ok1 && ok2 && ok3)
    cout << "AC" << nl;
  else
    cout << "WA" << nl;


  return 0;
}
