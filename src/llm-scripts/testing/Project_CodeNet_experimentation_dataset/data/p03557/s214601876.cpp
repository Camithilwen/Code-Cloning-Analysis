#include <bits/stdc++.h>
using namespace std;  
#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  int n;
  scanf("%d",&n);
  vector<int> a(n),b(n),c(n);

  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
  }

  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
  }
  sort(All(a));
  sort(All(b));
  sort(All(c));
  ll count=0;
  for (int j = 0; j < n; j++)
  {
    auto tmp = lower_bound(All(a),b[j]);
    auto l=tmp-a.begin();
      int tmp2 = c.end()-upper_bound(All(c),b[j]);
      count+=l*tmp2;
      
    
  }
  printf("%lld\n",count);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}