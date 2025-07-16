#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long inf = numeric_limits<long long>::max();
typedef long long ll;

ll calc(vector<ll> & vec, ll mode, ll add) {
  ll ans = 0;
  rep(i, vec.size()) {
    if (add ) {
      
    }
    if (vec[i] > 0 && mode != i) {
      ans += 1;
    }
  }
  return ans;
}

bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second > b.second); 
} 

vector<pair<ll, ll>> convert(vector<ll> &vec) {
  vector<pair<ll, ll>> seq;
  rep(i, vec.size()) {
    if (vec[i] == 0) {
      continue;
    }
    seq.push_back(make_pair((ll)i, vec[i]));
  }
  sort(seq.begin(), seq.end(), sortbysec);
  return seq;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> vec_even(pow(10, 5)+10, 0);
  vector<ll> vec_odd(pow(10, 5)+10, 0);
  int even_size = 0;
  int odd_size = 0;
  rep(i, n) {
    int x;
    cin >> x;
    if (i%2 == 0) {
      even_size++;
      vec_even[x]++;
    } else {
      odd_size++;
      vec_odd[x]++;
    }
  }
  vector<pair<ll, ll>> even_pairs = convert(vec_even);
  vector<pair<ll, ll>> odd_pairs = convert(vec_odd);
  ll res = pow(10, 8);
  if (even_pairs[0].first == odd_pairs[0].first) {
    ll a, b;
    a = even_size - even_pairs[0].second;
    b = odd_size - (odd_pairs.size() == 1 ? 0 : (odd_pairs[1].second));
    res = min(res, a + b);
      
    a = odd_size - odd_pairs[0].second;
    b = even_size - (even_pairs.size() == 1 ? 0 : (even_pairs[1].second));
    res = min(res, a + b);
  } else {
    ll a = even_size - even_pairs[0].second;
    ll b = odd_size - odd_pairs[0].second;
    res = a + b;
  }
  cout << res << endl;
  return 0;
}