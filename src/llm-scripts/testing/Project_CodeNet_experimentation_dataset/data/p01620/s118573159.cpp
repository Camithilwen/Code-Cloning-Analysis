#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000



int main(){
  int n;
  while(scanf("%d", &n), n){
    vector<int> k(n);
    rep(i,n){
      scanf("%d", &k[i]);
    }
    char s[103];
    scanf("%s", s);

    int len=strlen(s);
    rep(i,len){
      if(s[i]>='a' && s[i]<='z'){
	s[i]=s[i]-k[i%n];
	if(s[i]<'a'){
	  s[i]+='Z'-'a'+1;
	  if(s[i]<'A') s[i]+='z'-'A'+1;
	}
      } else {
	s[i]=s[i]-k[i%n];
	if(s[i]<'A'){
	  s[i]+='z'-'A'+1;
	  if(s[i]<'a') s[i]+='Z'-'a'+1;
	}
      }
    }

    cout<<s<<endl;

  }
  return 0;
}