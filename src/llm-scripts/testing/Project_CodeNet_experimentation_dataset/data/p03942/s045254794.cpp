#include<cstdio>
#include<algorithm>
const int N=1000007;
char s[N],t[N];int n,ans,sum[N];
int main()
{
    scanf("%d%s%s",&n,s+1,t+1);
    if(s[1]^t[1]) return !printf("-1");
    for(int i=n,f=0,k=0,p=n;i;--i)
    {
	f+=sum[i+k];
	if(p>i||t[i]^s[p])
        {
	    for(;p>0&&(p>i||t[i]^s[p]);--p);
	    if(p==i) continue;
	    if(p<=0) return !printf("-1");
	    ++k,++f,sum[i+k-1]=0,--sum[p+k-1];
        }
	ans=std::max(ans,f);
    }
    printf("%d",ans);
}
