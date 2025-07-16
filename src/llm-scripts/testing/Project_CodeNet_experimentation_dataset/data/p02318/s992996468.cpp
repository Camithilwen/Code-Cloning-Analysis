#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N=55555;
bool is_prime[MAX_N];
int prime[MAX_N];
int main(){
  int dp[1001][1001];
  for(int nn=0;nn<1;nn++){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<1001;i++)fill(dp[i],dp[i]+1001,0);
    for(int i=0;i<s1.size()+1;i++)dp[i][0]=i;
    for(int i=0;i<s2.size()+1;i++)dp[0][i]=i;
    for(int i=0;i<s1.size();i++){
      for(int j=0;j<s2.size();j++){
        int x=1;
        if(s1[i]==s2[j]) x=0;
        dp[i+1][j+1]=min(dp[i][j]+x,min(dp[i][j+1]+1,dp[i+1][j]+1));
      }
    }
    cout<<dp[s1.size()][s2.size()]<<endl;
  }
  return 0;
}

