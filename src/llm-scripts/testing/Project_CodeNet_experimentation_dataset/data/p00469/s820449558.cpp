#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)

int n, k;
int d[11];

inline int nextCombination(int comb)
{
  int x = comb & -comb, y = comb + x;
  return (((comb & ~y) / x) >> 1) | y;
}

template<typename T> inline void _tostr(const T t, string& s){ostringstream o;o<<t;s=o.str();}
template<typename T> inline string _tostr(const T t){ostringstream o;o<<t;return o.str();}
template<typename T> inline void _toint(const string s, T& n){istringstream i(s);i>>n;}
template<typename T> inline T _toint(const string s){istringstream i(s);T n;i>>n;return n;}


int main(int argc, char *argv[])
{
  while(cin >> n, n){
    cin >> k;
    rep(i, n) cin >> d[i];

    vector<string> res;

    for(int comb = (1 << k) - 1; comb < (1 << n); comb = nextCombination(comb)){
      vector<int> vec;
      rep(mask, n) if(comb & 1 << mask) vec.push_back(mask);
      do{
        string s = "";
        rep(i, k) s += _tostr(d[vec[i]]);
        res.push_back(s);
      }while(next_permutation(vec.begin(), vec.begin() + k));
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << endl;
  }
  
  return 0;
}