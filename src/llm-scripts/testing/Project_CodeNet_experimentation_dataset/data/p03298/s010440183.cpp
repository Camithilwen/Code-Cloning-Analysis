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
#define vvs std::vector<std::vector<string> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[]) {
  int N;
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
  vvs str = vv(0, 2, "", string);
  for(int i=0;i<(1<<N);i++){
    int n = i+(1<<20), count=0;
    string ah = "", bh = "";
    while(count<N){
      if(n%2==1) ah += T[count];
      if(n%2==0) bh += T[count];
      count++;
      n/=2;
    }
    str.push_back(std::vector<string> {ah, bh});
  }
  sort(str.begin(), str.end());
  for(int i=0;i<(1<<N);i++){
    int n = i + (1<<20), count=0;
    string ah="", bh="";
    while(count<N){
      if(n%2==1) ah += S[count];
      if(n%2==0) bh += S[count];
      count++;
      n/=2;
    }
    int k = upper_bound(str.begin(), str.end(), std::vector<string> {ah,bh}) - lower_bound(str.begin(), str.end(), std::vector<string> {ah, bh});
    ans += k;
  }
  std::cout << (!flag?0:ans) << '\n';
  return 0;
}
