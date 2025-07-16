#include <iostream>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main()	{
  ll n; 
  cin >> n;
  ll a;
  unordered_set<ll> sheet;
  for (ll i = 0; i < n; i++)	{
    cin >> a;
    if (sheet.find(a) == sheet.end())	{
      //not present, insert
      sheet.insert(a);
    }
    else	{
      sheet.erase(a);
    }
  }
  cout << sheet.size() << endl; 
  return 0;
}