#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  while(cin>>a>>b>>c){
    if(a==0&&b==0&&c==0) break;
  int ans[a+b+c+1];
  for(int i=1;i<=a+b+c;i++) ans[i] = 2;
  int n;
  cin >> n;
  int ag[n],bg[n],cg[n],r[n];
  for(int i=0;i<n;i++){
    cin >> ag[i] >> bg[i] >> cg[i] >> r[i];
    if(r[i]==1) ans[ag[i]] = ans[bg[i]] = ans[cg[i]] = 1;
  }
  for(int i=0;i<n;i++){
    if(r[i]==0){
      if(ans[ag[i]]==2&&ans[bg[i]]==1&&ans[cg[i]]==1) ans[ag[i]] = 0;
      if(ans[ag[i]]==1&&ans[bg[i]]==2&&ans[cg[i]]==1) ans[bg[i]] = 0;
      if(ans[ag[i]]==1&&ans[bg[i]]==1&&ans[cg[i]]==2) ans[cg[i]] = 0;
    }
  }
  for(int i=1;i<=a+b+c;i++) cout << ans[i] << endl;
  }
  return 0;
}