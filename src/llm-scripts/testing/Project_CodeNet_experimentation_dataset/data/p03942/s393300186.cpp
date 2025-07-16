#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=1000000+10;
char a[maxn],b[maxn],sta[maxn];
int dl[maxn*3][2];
int i,j,k,l,t,n,m,tot,head,tail,ans,mi,cnt,num;
bool czy;
int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    scanf("%s",b+1);
    fo(i,1,n+1)
        if (i>n||a[i]!=b[i]) break;
    if (i>n){
        printf("0\n");
        return 0;
    }
    czy=1;
    mi=n+1;
    i=n;k=n+1;
    head=n+1;tail=n;
    while (i){
        j=i;
        while (j>1&&b[j-1]==b[i]) j--;
        k=min(k,j);
        while (k&&a[k]!=b[i]) k--;
        if (!k){
            czy=0;
            break;
        }
        while (head<=tail){
            if (dl[tail][0]-num>i) tail--;
            else break;
        }
        cnt++;
        num++;
        head--;
        dl[head][0]=k+num;
        dl[head][1]=1-cnt;
        ans=max(ans,dl[tail][1]+cnt);
        i=j-1;
    }
    if (!czy) printf("-1\n");
    else printf("%d\n",ans);
}