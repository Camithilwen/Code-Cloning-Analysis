#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100005],b[100005];
int q[100005];

int main() {
  int n,s;
  scanf("%d%d",&n,&s);
  int id=0;
  for(int i=1;i<=n;i++) {
  	scanf("%lld%lld",&a[i],&b[i]);
  	if (a[i]<s) id=i;
  }
  int cnt=0,l=1,r=n;
  while ((l<=id)^(r<=id))
    if (b[l]>=b[r]) {
    	q[++cnt]=a[r];
    	b[l]+=b[r];
    	r--;
	}
	else {
		q[++cnt]=a[l];
		b[r]+=b[l];
		l++;
	}
  if (r<=id) {
  	for(int i=l;i<=r;i++) q[++cnt]=a[i];
  }
  else {
  	for(int i=r;i>=l;i--) q[++cnt]=a[i];
  }
  q[cnt+1]=s;
  ll ans=0;
  for(int i=1;i<=cnt;i++) ans+=abs(q[i]-q[i+1]);
  printf("%lld\n",ans);
  return 0;
}