#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto x:v)cerr<<x<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define EPS 1e-9
typedef long long ll;

ll levenshtein(string s1,string s2){
  long long n = s1.size();
  long long m = s2.size();
  long long DP[n+1][m+1]={0};
  for(long long i = 0;i < n+1;i++)DP[i][0] = i;
  for(long long j = 0;j < m+1;j++)DP[0][j] = j;
  for(long long i = 1;i < n+1;i++){
    for(long long j = 1;j < m+1;j++){
      long long cost = (s1[i-1]==s2[j-1] ? 0 :1);
      DP[i][j] = min({DP[i-1][j]+1,DP[i][j-1]+1,DP[i-1][j-1]+cost});
    }
  }
  return DP[n][m];
}

signed main(){
  string s1,s2;
  cin >> s1 >> s2;
  cout << levenshtein(s1,s2) << endl;
}
