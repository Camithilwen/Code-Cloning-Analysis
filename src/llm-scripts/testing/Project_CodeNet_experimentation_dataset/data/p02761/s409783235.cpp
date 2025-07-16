#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> box(n,10);
  int ans = 0;
  rep(i,m){
    int s;
    int c;
    cin >> s >>c;
    s--;
    if(s==0&&c==0&&n!=1) ans = -1;
    if(box[s]==c)continue;
    if(box[s]==10)box[s]=c;
    if(box[s]!=c)ans = -1;
  }
  if(n==1){
    if(ans==-1) cout << -1 << endl;
    else if(box[0]==10)cout << 0 << endl;
    else cout << box[0] << endl;
    return 0;
  }
  rep(i,n){
    if((i==0)&&box[i]==10)box[i]=1;
    if(box[i]==10)box[i]=0;
  }
  if(ans==-1)cout<<-1 <<endl;
  else {
    rep(i,n) cout << box[i];
    cout << endl;
  }
  return 0;
}
