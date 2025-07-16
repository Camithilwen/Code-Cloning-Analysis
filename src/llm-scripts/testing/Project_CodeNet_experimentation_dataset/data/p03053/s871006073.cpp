#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
int main(){
int H, W, ans=1; cin >> H >> W; string A[H];
REP(i, H){ cin >> A[i]; }
int B[H][W]={}; vector< pair<int, int> > C;
REP(i, H){ REP(j, W){ 
  if(A[i][j]=='#'){  B[i][j]=1; C.push_back(make_pair(i, j)); } 
} }
REP(i, H*W){
if((int)C.size()==H*W){ cout << ans-1 << "\n"; return 0; }
int a=C[i].first, b=C[i].second, c=B[a][b]+1;
if(a>0&&!B[a-1][b]){ B[a-1][b]=c; C.push_back(make_pair(a-1, b)); }
if(b>0&&!B[a][b-1]){ B[a][b-1]=c; C.push_back(make_pair(a, b-1)); }
if(a<H-1&&!B[a+1][b]){ B[a+1][b]=c; C.push_back(make_pair(a+1, b)); }
if(b<W-1&&!B[a][b+1]){ B[a][b+1]=c; C.push_back(make_pair(a, b+1)); }
ans=c;
}
}