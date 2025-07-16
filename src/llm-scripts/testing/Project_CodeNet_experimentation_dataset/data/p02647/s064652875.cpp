#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,m,a[N+9];
int cnt[N+9];

bool Get_a(){
  for (int i=1;i<=n;++i) cnt[i]=0;
  for (int i=1;i<=n;++i){
	int l=max(i-a[i],1),r=min(i+a[i],n);
	++cnt[l];--cnt[r+1];
  }
  for (int i=1;i<=n;++i) a[i]=cnt[i]+=cnt[i-1];
  for (int i=1;i<=n;++i)
	if (a[i]<n) return 0;
  return 1;
}

int main(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  for (int i=1;i<=m;++i)
	if (Get_a()) break;
  for (int i=1;i<=n;++i)
	printf("%d ",a[i]);
  puts("");
  return 0;
}