#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
  int n,v,p;
  long long m;
  scanf("%d%lld%d%d",&n,&m,&v,&p);
  std::vector<long long> A(n);
  for(int i=0;i<n;i++){
    scanf("%lld",&A[i]);
  }
  std::sort(A.begin(),A.end());
  int l=-1,r=n-p;
  while(l+1<r){
    int d=(l+r)/2;
    bool F=true;
    if(A[d]+m<A[n-p]){
      F=false;
    }
    else{
      long long S=0ll;
      for(int i=d+1;i<=n-p;i++){
	S+=A[d]+m-A[i];
      }
      if(S>=std::max(v-p-d,0)*m){
	F=true;
      }
      else{
	F=false;
      }
    }
    if(F){
      r=d;
    }
    else{
      l=d;
    }
  }
  printf("%d\n",n-r);
  return 0;
}
