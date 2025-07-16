#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
typedef unsigned long long ull;
#define vvi std::vector<std::vector<int> >
#define vvu std::vector<std::vector<ull> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[]) {
  int N;
  ull B = 10000007;
  ll ans = 0;
  string s, S, t, T="";
  std::cin >> N;
  std::cin >> s;
  S = s.substr(0, N);
  t = s.substr(N);
  for(int i=0;i<N;i++) T+=t[N-1-i];
  std::vector<int> num(26, 0);
  for(int i=0;i<N;i++) num[S[i]-'a']++, num[T[i]-'a']--;
  bool flag = true;
  for(int i=0;i<26;i++) if(num[i]!=0) flag = false;
  vvu hash = vv(0, 2, 0, ull);
  for(int i=0;i<(1<<N);i++){
    int n = i+(1<<20), count=0;
    ull ah = 0, bh = 0;
    while(count<N){
      if(n%2==1) ah = ah * B + T[count];
      if(n%2==0) bh = bh * B + T[count];
      count++;
      n/=2;
    }
    hash.push_back(std::vector<ull>{ah, bh});
  }
  sort(hash.begin(), hash.end());
  for(int i=0;i<(1<<N);i++){
    int n = i + (1<<20), count=0;
    ull ah = 0, bh = 0;
    while(count<N){
      if(n%2==1) ah = ah * B + S[count];
      if(n%2==0) bh = bh * B + S[count];
      count++;
      n/=2;
    }
    auto itr = lower_bound(hash.begin(), hash.end(), std::vector<ull> {ah, bh});
    auto itr2 = lower_bound(hash.begin(), hash.end(), std::vector<ull> {ah, bh+1});
    ans += itr2 - itr;
  }
  std::cout << (!flag?0:ans) << '\n';
  return 0;
}
