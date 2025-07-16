#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(std::string A){
  ll x = 0;
  ll len = A.size();
  for(ll i=0; i<26; i++) {
    ll cnt = 0;
    for(auto c : A) {
      if(c == 'a'+i)
	cnt++;
    }
    x += cnt*(cnt-1) / 2;
  }
  std::cout << (len * (len-1))/2 - x + 1<< std::endl;
}

int main(){
  std::string A;
  std::cin >> A;
  solve(A);
  return 0;
}

