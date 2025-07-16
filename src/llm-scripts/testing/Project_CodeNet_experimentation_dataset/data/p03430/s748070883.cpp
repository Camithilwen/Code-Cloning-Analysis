// luogu-judger-enable-o2
#pragma GCC optimize(1)
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
#define R register
using namespace std;
char s[351];int len,k;
int f[351][351][351],ans;
inline void read(R int &x)
{
    x=0;R int f=1;
	R char c=getchar();
	while(c<'0'||c>'9')
	{
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>=48&&c<=57)
	{
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
	x=x*f;
}
inline void input_data()
{
	char ch=getchar();
	while(ch>='a'&&ch<='z')
		s[++len]=ch,ch=getchar();
	read(k);return;
}
int dfs(R int k,R int l,R int r)
{
	if(l>r) return false;
	if(l==r) return s[l]==s[r];
	if(f[k][l][r]) return f[k][l][r];
	f[k][l][r]=max(dfs(k,l+1,r),dfs(k,l,r-1));
	if(s[l]==s[r]) f[k][l][r]=max(f[k][l][r],dfs(k,l+1,r-1)+2);
	if(k>=1) f[k][l][r]=max(f[k][l][r],dfs(k-1,l+1,r-1)+2);
	return f[k][l][r];
}
int main()
{
	input_data();
	for(R int i=0;i<=k;++i)
		ans=max(ans,dfs(i,1,len));
	printf("%d\n",ans);
	return 0;
}