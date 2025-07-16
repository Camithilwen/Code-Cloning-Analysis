#include <bits/stdc++.h>

using namespace std;

struct node{
	long long x,p;
}a[100010];

bool cmp(node a,node b){
	return a.x<b.x;
}

long long n,s,ans;

int main(){
	scanf("%lld%lld",&n,&s);
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].p);
	sort(a+1,a+n+1,cmp);
	long long l=n,l1=1;
	while (l>=l1){
		if (a[l].x<=s){
			ans+=s-a[l1].x;
			break;
		}
		if (a[l1].x>=s){
			ans+=a[l].x-s;
			break;
		}
		ans+=a[l].x-a[l1].x;
		if (a[l1].p>=a[l].p)
			while (l>l1 && a[l1].p>=a[l].p)	a[l1].p+=a[l].p,l--;
		else
			while (l>l1 && a[l].p>a[l1].p)	a[l].p+=a[l1].p,l1++;
	}
	printf("%lld",ans);
	return 0; 
} 