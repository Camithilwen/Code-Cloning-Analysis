#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long h,w,k,mod=1000000007;
  cin >> h >> w >> k;
  if(w==1) {
    cout << 1 << endl;
    return 0;
  }
  vector<long> sayu(w-1),sonomama(w);
  vector<vector<long>> amida(h+1,vector<long>(w));
  amida[0][0]=1;
  for(long bit=0;bit<(1<<(w-1));bit++) {
    bool imp=false;
    for(long i=0;i<w-2;i++) {
      if((bit&(1<<i))&&(bit&(1<<(i+1)))) imp=true;
    }
    if(imp) continue;
    for(long i=0;i<w-1;i++) if(bit&(1<<i)) sayu[i]++;
    
    if(!(bit&(1<<0))) sonomama[0]++;
    if(!(bit&(1<<(w-2)))) sonomama[w-1]++;
    for(long i=1;i<w-1;i++) if(!(bit&(1<<(i-1))||bit&(1<<i))) sonomama[i]++;
  }
  
  for(long i=0;i<h;i++) {
    for(long j=0;j<w-1;j++) {
      amida[i+1][j]=(amida[i+1][j]+amida[i][j+1]*sayu[j])%mod;
      amida[i+1][j+1]=(amida[i+1][j+1]+amida[i][j]*sayu[j])%mod;
    }
    for(long j=0;j<w;j++) {
      amida[i+1][j]=(amida[i+1][j]+amida[i][j]*sonomama[j])%mod;
    }
  }
  
  cout << amida[h][k-1] << endl;
}