#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<char,int> P;

signed main(){
  string str;
  cin>>str;

  vector<P> A;
  int idx=0;
  while(idx<str.size()){
    char ch = str[idx];
    int cnt=0;
    while(str[idx] == ch) idx++,cnt++;
    A.push_back(P(ch,cnt));
  }

  int ans = 0;
  for(int i=1;i<(int)A.size() - 1;i++){
    if(A[i-1].first!='J' || A[i].first !='O' || A[i+1].first !='I')continue;
    int J = A[i-1].second;
    int O = A[i].second;
    int I = A[i+1].second;
    if(O<=I && O<=J) ans = max(ans,min(O,min(J,I)));
  }
  cout<<ans<<endl;
    
  return 0;
}