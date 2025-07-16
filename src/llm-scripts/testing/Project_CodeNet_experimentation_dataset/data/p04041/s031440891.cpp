#include <cstdio>
typedef long long ll;

int n,x,y,z,s,t;
int f[50][1<<17],Ans=1;
const int p=1000000007;

int main()
{
    scanf("%d%d%d%d",&n,&x,&y,&z);
    for(int i=1;i<=n;++i)Ans=(ll)Ans*10%p;
    t=(1<<(x-1))|(1<<(x+y-1))|(1<<(x+y+z-1));
    s=(1<<(x+y+z))-1;
    f[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=s;++j)
            for(int k=1;k<=10;++k)
            {
                int r=(j<<k|(1<<(k-1)))&s;
                if((r&t)!=t)(f[i][r]+=f[i-1][j])%=p;
            }
    for(int i=0;i<=s;++i)Ans=(Ans-f[n][i]+p)%p;
    printf("%d\n",Ans);
    return 0;
}
