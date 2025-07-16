#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  while(true){
    int n,m,p[1001];
    vector<int> a;
    scanf("%d %d",&n,&m);
    if(n==0&&m==0) return 0;
    p[0] = 0;
    for(int i=0;i<n;i++) scanf("%d",p+i+1);
    n++;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        a.push_back(p[i]+p[j]);
      }
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int ans = 0;
    for(int i=0;i<a.size();i++){
      int x = m - a[i];
      int j = upper_bound(a.begin(),a.end(),x) - a.begin();
      if(j!=0) ans = max(ans,a[i]+a[j-1]);
    }
    printf("%d\n",ans);
  }
}