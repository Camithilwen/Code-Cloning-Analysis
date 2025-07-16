#include<bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;



/*
	需要维护的是
	a[i]区间最大值
	a[i]-i的区间最小值 
*/
#define inf 1000000
#define M 200005
int f[M<<2],laz[M<<2],mx[M<<2];
int n,m;
int res,pos;
void up(int p){
	mx[p]=max(mx[ls],mx[rs]);
	f[p]=min(f[ls],f[rs]);
}
void down(int l,int mid,int r,int p){
	if (laz[p]){
		laz[ls]=laz[rs]=laz[p];
		mx[ls]=mx[rs]=laz[p];
		f[ls]=laz[p]-mid;
		f[rs]=laz[p]-r;
		laz[p]=0;
	}
}
void build(int l,int r,int p){
	if (l==r){
		mx[p]=l;
		f[p]=0;
		return ;
	}
	
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	up(p);
}
void pt(int l,int r,int p){
	if (l==r){
		printf("%d ",mx[p]);
		return ;
	}
	int mid=(l+r)>>1;
	down(l,mid,r,p);
	pt(l,mid,ls);
	pt(mid+1,r,rs);
	up(p);
}
void qu(int l,int r,int p){
	if (mx[p]<pos)return; 
	if (l==r){
		res=l;
		return; 
	}
	int mid=(l+r)>>1;
	down(l,mid,r,p);
	qu(l,mid,ls);
	if (res)return;
	qu(mid+1,r,rs);
}
int qu(int k){
	res=0;
	pos=k;
	qu(1,m+1,1);
	return res;
}
void upd(int l,int r,int x,int y,int k,int p){
	if (l==x&&r==y){
		laz[p]=k;
		mx[p]=k;
		f[p]=k-r;
		return ;
	}
	int mid=(l+r)>>1;
	down(l,mid,r,p); 
	if (y<=mid){
		upd(l,mid,x,y,k,ls);
	}
	else if (x>mid){
		upd(mid+1,r,x,y,k,rs);
	}
	else{
		upd(l,mid,x,mid,k,ls);
		upd(mid+1,r,mid+1,y,k,rs);
	}
	up(p);
} 
void upd(int l,int r,int k){
	int resl=qu(l);
	int resr=qu(r+1)-1;
//	printf("%d %d\n",resl,resr);
	if (resl<=resr&&resr<=m)upd(1,m+1,resl,resr,k,1);
}
int qu(int l,int r,int x,int y,int p){
	if (l==x&&r==y){
//		printf("%d %d    %d\n",x,y,f[p]);
		return f[p];
	}
	int mid=(l+r)>>1;
	down(l,mid,r,p);
	if (y<=mid)return qu(l,mid,x,y,ls);
	if (x>mid)return qu(mid+1,r,x,y,rs);
	return min(qu(l,mid,x,mid,ls),qu(mid+1,r,mid+1,y,rs));
}
int calc(int i){
	int res=qu(1,m+1,1,m,1); 
	if (res>=m)return -1;
	return res+i;
}
/*
4 4
2 4
1 1
2 3
2 4
*/

int main(){
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	int i,l,r;
	build(1,m+1,1);
	for (i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		if (r==m){
			upd(l,r,inf);
		}
		else{
			upd(l,r,r+1);
		}
//		pt(1,m+1,1); printf("\n");
		printf("%d\n",calc(i));
	}
	return 0;
} 