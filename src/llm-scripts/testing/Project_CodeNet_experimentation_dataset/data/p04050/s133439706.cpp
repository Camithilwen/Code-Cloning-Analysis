#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
int f[105];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,a,b,t,p=0;
	cin>>n>>m;
    a=-1;
	b=-1;
    for(int i=1;i<=m;i++)
    {
    	cin>>f[i];
        if(~f[i]&1)
		{
			continue;
		}
        else if(p==0)
		{
			a=i;
		}
		else if(p==1)
		{
			b=i;
		}
        else
		{
			cout<<"Impossible"<<endl;
			exit(0);
		}
		p++;
    }
    if(a==-1) a=1;
    if(b==-1) b=m;
    t=f[1];
    f[1]=f[a];
    f[a]=t;
    t=f[m];
    f[m]=f[b];
    f[b]=t;
    if(m==1)
	{
		if(f[1]==1)
		{
			cout<<1;
			cout<<endl;
			cout<<1;
			cout<<endl;
			cout<<1;
			cout<<endl;
			exit(0);
		}
	}
    for(register int i=1;i<=m;i++)
    {
    	cout<<f[i]<<' ';
	}
    if(m==1)
	{
		f[1]--;
		cout<<endl;
		cout<<2;
		cout<<endl;
		cout<<f[1];
		cout<<' ';
		cout<<1;
		cout<<endl;
		exit(0);
	}
	cout<<endl;
	if(f[m]>1)
	{
		cout<<m;
	}else{
		cout<<m-1;
	}
	cout<<endl;
	cout<<f[1]+1;
	cout<<' ';
    for(register int i=2;i<m;i++)
	{
		cout<<f[i]<<' ';
	}
    if(f[m]>1)
	{
		cout<<f[m]-1<<endl;
	}
    return 0;
}