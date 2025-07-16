#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,i,j,k,ans=0;
  cin>>N;
  vector<int> L(N);
  for (i=0;i<N;i++) cin>>L[i];
  for (i=0;i<N-2;i++) {
    for (j=i+1;j<N-1;j++) {
      if (L[i]==L[j]) continue;
      for (k=j+1;k<N;k++) {
        if (L[i]==L[k] || L[j]==L[k]) continue;
        if (L[i] < L[j]+L[k] && L[j] < L[i]+L[k] && L[k] < L[j]+L[i]) ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
