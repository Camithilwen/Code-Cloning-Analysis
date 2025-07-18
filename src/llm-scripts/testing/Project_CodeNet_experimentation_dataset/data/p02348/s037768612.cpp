#include<iostream>
using namespace std;
#include<vector>
#include<functional>
template<typename T>
struct lazysegtree{
	function<T(T,T)>calcfn,lazycalcfn;
	function<T(T,T,unsigned int)>updatefn;
	int n;
	T defvalue,lazydefvalue;
	vector<T>dat,lazy;
	vector<bool>lazyflag;
	lazysegtree(int n_=0,T defvalue_=0,
		function<T(T,T)>calcfn_=[](T a,T b){return a+b;},
		function<T(T,T)>lazycalcfn_=[](T a,T b){return a+b;},
		function<T(T,T,unsigned int)>updatefn_=[](T a,T b,unsigned int width){return a+b*width;},
		T lazydefvalue_=0
	):defvalue(defvalue_),lazydefvalue(lazydefvalue_),
		calcfn(calcfn_),lazycalcfn(lazycalcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,defvalue);
		lazy.assign(2*n-1,lazydefvalue);
		lazyflag.assign(2*n-1,false);
	}
	void copy(vector<T>v)
	{
		for(int i=0;i<v.size();i++)dat[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)dat[i]=calcfn(dat[2*i+1],dat[2*i+2]);
	}
	void eval(int i,int l,int r)
	{
		if(lazyflag[i])
		{
			dat[i]=updatefn(dat[i],lazy[i],r-l);
			if(r-l>1)
			{
				lazy[2*i+1]=lazycalcfn(lazy[2*i+1],lazy[i]);
				lazy[2*i+2]=lazycalcfn(lazy[2*i+2],lazy[i]);
				lazyflag[2*i+1]=lazyflag[2*i+2]=true;
			}
			lazy[i]=lazydefvalue;
			lazyflag[i]=false;
		}
	}
	void update(int a,int b,T x,int k=0,int l=0,int r=-1)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]=lazycalcfn(lazy[k],x);
			lazyflag[k]=true;
			eval(k,l,r);
		}
		else
		{
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			dat[k]=calcfn(dat[2*k+1],dat[2*k+2]);
		}
	}
	T query(int a,int b,int k=0,int l=0,int r=-1)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return defvalue;
		else if(a<=l&&r<=b)return dat[k];
		else return calcfn(
			query(a,b,2*k+1,l,(l+r)/2),
			query(a,b,2*k+2,(l+r)/2,r)
		);
	}
};
main()
{
	int n,q;cin>>n>>q;
	lazysegtree<int>S(n,2147483647,[](int a,int b){return a==2147483647?b:a;},[](int a,int b){return b;},[](int a,int b,unsigned int c){return b;});
	for(int i=0;i<q;i++)
	{
		int c;cin>>c;
		if(c)
		{
			int s;cin>>s;
			cout<<S.query(s,s+1)<<endl;
		}
		else
		{
			int s,t,x;cin>>s>>t>>x;
			S.update(s,t+1,x);
		}
	}
}
