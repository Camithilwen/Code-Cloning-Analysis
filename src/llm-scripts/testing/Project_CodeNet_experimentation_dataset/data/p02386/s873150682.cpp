#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
const int N=100+5;
char s[100+10];
char ans[][10]={
	"No\n",
	"Yes\n"
};
struct DICE{
	int u,s,e,w,n,d;
	DICE (int u=0,int s=0,int e=0,int w=0,int n=0,int d=0):u(u),s(s),e(e),w(w),n(n),d(d){}
	DICE fW(){
		DICE tmp;
		tmp.s=this->s;
		tmp.n=this->n;
		tmp.e=this->d;
		tmp.w=this->u;
		tmp.u=this->e;
		tmp.d=this->w;
		return tmp;
	}
	DICE fS(){
		DICE tmp;
		tmp.s=this->u;
		tmp.n=this->d;
		tmp.e=this->e;
		tmp.w=this->w;
		tmp.d=this->s;
		tmp.u=this->n;
		return tmp;
	}
	DICE fE(){
		DICE tmp;
		tmp.s=this->s;
		tmp.n=this->n;
		tmp.e=this->u;
		tmp.w=this->d;
		tmp.d=this->e;
		tmp.u=this->w;
		return tmp;
	}
	DICE fN(){
		DICE tmp;
		tmp.s=this->d;
		tmp.n=this->u;
		tmp.e=this->e;
		tmp.w=this->w;
		tmp.d=this->n;
		tmp.u=this->s;
		return tmp;
	}
	int right(int t,int f){
		if(t==this->u)
		{
			if(f==this->s)return this->e;
			else if(f==this->e)return this->n;
			else if(f==this->n)return this->w;
			else if(f==this->w)return this->s;
			else return -1;
		}
		else if(t==this->s){
			DICE tmp=(*this).fN();
			return tmp.right(t,f);
		}
		else if(t==this->e){
			DICE tmp=(*this).fW();
			return tmp.right(t,f);
		}
		else if(t==this->n){
			DICE tmp=(*this).fS();
			return tmp.right(t,f);
		}
		else if(t==this->w){
			DICE tmp=(*this).fE();
			return tmp.right(t,f);
		}
		else if(t==this->d){
			DICE tmp=(*this).fE().fE();
			return tmp.right(t,f);
		}
		else return -1;
		}
};
DICE A[N];
bool check(DICE x,DICE y){
	int ax[]={
		x.s,x.e,x.n,x.w
	};
	int ay[]={
		y.s,y.e,y.n,y.w
	};
	if(x.u==y.u){
		if(x.d==y.d){
			int cnt=0;
			while(cnt<=4){
				while(ax[cnt]!=ay[0]&&cnt<=4)
					cnt++;
				int i=0;
				while(ax[(i+cnt)%4]==ay[i]&&i<=4)
					i++;
				if(i==4)return 1;
				cnt++;
			}
			
		}
	}
	return 0;
}
bool sovle(DICE x,DICE y){
	if(check(x,y))return 1;
	if(check(x.fE(),y))return 1;
	if(check(x.fW(),y))return 1;
	if(check(x.fN(),y))return 1;
	if(check(x.fS(),y))return 1;
	if(check(x.fS().fS(),y))return 1;
	return 0;
}
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	int n;scanf("%d", &n);
	int t=0;
	int a[6];
	bool flag=1;
	for(int i=0;i<6;i++){
		scanf("%d", &a[i]);
	}
	A[0]=DICE(a[0],a[1],a[2],a[3],a[4],a[5]);
	t++;
	while(t<n){
	for(int i=0;i<6;i++){
		scanf("%d", &a[i]);
	}
	A[t]=DICE (a[0],a[1],a[2],a[3],a[4],a[5]);
	for(int i=0;i<t;i++)
	{
		if(sovle(A[i],A[t])){flag=0;
//			cout<<i<<' '<<t<<endl;
		}
	}
	t++;
	}
	printf("%s", ans[flag]);
//	printf("%s", ans[solve(dice,dice2)]);
//	DICE I
//	scanf("%s", s);
//	int len=strlen(s);
//	for(int i=0;i<len;i++){
//		switch(s[i]){
//			case'S':dice=dice.fS();break;
//			case'E':dice=dice.fE();break;
//			case'W':dice=dice.fW();break;
//			case'N':dice=dice.fN();break;
//		}
//	}
//	printf("%d\n", dice.u);
//
	return 0;
}
//aoj1_11_a.cc

//AC