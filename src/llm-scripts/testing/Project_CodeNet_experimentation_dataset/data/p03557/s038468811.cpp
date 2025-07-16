#include <stdio.h>
#include <algorithm>
int n;
int a[100010];
int b[100010];
int c[100010];
long long psum_b[100010];
long long ans;
long long find_bc(int st,int ed,int x){
	int mid = (st+ed)/2;
	if(ed-st<=1){
		if(x<c[st]) return n-st;
		if(x>=c[ed]) return n-ed-1;
		return n-ed;
	}
	if(c[mid]<=x) return find_bc(mid,ed,x);
	return find_bc(st,mid,x);
}
long long find_ab(int st,int ed,int x){
	int mid = (st+ed)/2;
	if(ed-st<=1){
		if(x<b[st]) return psum_b[st];
		if(x>=b[ed]) return psum_b[ed+1];
		return psum_b[ed];
	}
	if(b[mid]<=x) return find_ab(mid,ed,x);
	return find_ab(st,mid,x);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	std::sort(b,b+n);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	std::sort(c,c+n);
	for(int i=n-1;i>=0;i--){
		psum_b[i]=psum_b[i+1]+find_bc(0,n-1,b[i]);
	}
	for(int i=0;i<n;i++){
		ans+=find_ab(0,n-1,a[i]);
	}
	printf("%lld\n",ans);
}