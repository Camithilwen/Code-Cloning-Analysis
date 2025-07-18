#include<iostream>
using namespace std;
#include<vector>
#include<functional>
template<typename T>
struct dualsegtree{
	function<T(T,T)>lazycalcfn,updatefn;
	int n;
	T lazydefvalue;
	vector<T>dat,lazy;
	vector<bool>lazyflag;
	dualsegtree(int n_=0,T defvalue=0,
		function<T(T,T)>lazycalcfn_=[](T a,T b){return a+b;},
		function<T(T,T)>updatefn_=[](T a,T b){return a+b;},
		T lazydefvalue_=0
	):lazydefvalue(lazydefvalue_),
		lazycalcfn(lazycalcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(n,defvalue);
		lazy.assign(n-1,lazydefvalue);
		lazyflag.assign(n-1,false);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i]=v[i];
		lazy.assign(n-1,lazydefvalue);
		lazyflag.assign(n-1,false);
	}
	void update(int a,int b,T x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			if(k<n-1)
			{
				lazy[k]=lazycalcfn(lazy[k],x);
				lazyflag[k]=true;
			}
			else dat[k-n+1]=updatefn(dat[k-n+1],x);
		}
		else
		{
			if(lazyflag[k])
			{
				update(0,n,lazy[k],k*2+1,l,(l+r)/2);
				update(0,n,lazy[k],k*2+2,(l+r)/2,r);
				lazy[k]=lazydefvalue;
				lazyflag[k]=false;
			}
			update(a,b,x,k*2+1,l,(l+r)/2);
			update(a,b,x,k*2+2,(l+r)/2,r);
		}
	}
	T query(int i)
	{
		T ret=dat[i];
		i+=n-1;
		while(i>0)
		{
			i=(i-1)/2;
			if(lazyflag[i])ret=updatefn(ret,lazy[i]);
		}
		return ret;
	}
};
main()
{
	int N,Q;
	cin>>N>>Q;
	dualsegtree<int>P(N,(int)((1LL<<31)-1),
		[](int a,int b){return b;},[](int a,int b){return b;});
	for(;Q--;)
	{
		int q;cin>>q;
		if(q==0)
		{
			int s,t,x;cin>>s>>t>>x;
			P.update(s,t+1,x);
		}
		else
		{
			int i;cin>>i;cout<<P.query(i)<<endl;
		}
	}
}

