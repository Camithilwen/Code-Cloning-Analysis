#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,a[2000];
vector<int> t;
int main(){
  a[0]=0;
  while(cin>>n>>m&&n&&m){
    t.clear();
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
      for(int j=i;j<=n;j++){
	t.push_back(-(a[i]+a[j]));
      }
    }
    sort(t.begin(),t.end());
    int ans=0;
    for(int i=0;i<(int)t.size();i++){
      int x=-t[i];
      int y=m-x;
      if(y<0)continue;
      vector<int> :: iterator it;
      it = upper_bound(t.begin(),t.end(),-y);
      if(it==t.end())continue;
      int z = *it;
      ans=max(ans,x-z);
    }
    cout<<ans<<endl;
  }
  return 0;
}