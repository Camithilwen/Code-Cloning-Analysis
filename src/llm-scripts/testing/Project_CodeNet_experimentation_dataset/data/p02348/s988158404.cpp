#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)

using namespace std;

typedef pair<int,int>P;

const int N = 1 << 17;

//?????????????????????0?§???????
//????°????????±???????????????°??????(RMQ)

//?????°???????????¨???????????°??????????????????

int n,n_,q,ud[2*N-1],t[2*N-1];

//?????????
//n_???x??\??????????°????2????????????
void init(int x)
{
	//?°????????????????????´???°???2???????????????
	n_=1;
	while(n_<x){
		n_*=2;
	}
	rep(i,2*n_-1){
		ud[i] = (int)((1LL<<31) -1LL);
		t[i] = -1;
	}
}

//k????????????????????§??????
int find(int k)
{
	P res;
	//????????????
	k += n_-1;
	res.first = ud[k];
	res.second = t[k];
	//?????????????????´??°
	while(k>0){
		k = (k-1)/2;
		if(t[k] > res.second){
			res.first = ud[k];
			res.second = t[k];
		}	
	}
	return res.first;
}

//[a,b)???????°????????±??????????
//k??????????????????
//????????????query(a,b,0,0,n_)??¨???????????¶???(n_??¨???????????¨?????¨???)
void update(int a,int b,int k,int l,int r,int val,int id)
{
	if(r <= a || b <= l){
		return;
	}
	if(a <= l && r <= b){
		ud[k] = val;
		t[k] = id;
	}else{
		update(a,b,2*k+1,l,(l+r)/2,val,id);
		update(a,b,2*k+2,(l+r)/2,r,val,id);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	init(n);
	rep(i,q){
		int x;
		scanf("%d",&x);
		if(x==0){
			int s,t,u;
			scanf("%d%d%d",&s,&t,&u);
			update(s,t+1,0,0,n_,u,i);
		}else{
			int s;
			scanf("%d",&s);
			printf("%d\n",find(s));
		}
	}
	return 0;
}