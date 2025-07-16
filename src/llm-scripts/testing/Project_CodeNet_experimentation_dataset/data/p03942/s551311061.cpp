#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char a[maxn],b[maxn];
int q[maxn],head,tail;
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",a+1,b+1);
    if(strcmp(a+1,b+1)==0)
    {
        puts("0");
        return 0;
    }
    int ans=0;
    head=tail=maxn-2;
    //q[tail++]=n+1;
    int last=n;
    int tag=0;
    for(int l=n,r;l;l--)
    {
        r=l;
        while(b[l]==b[l-1]) l--;
        while(last){
            if(last>l||a[last]!=b[l]) last--;
            else break;
        }
        //printf("%d %d %d\n",l,r,last);
        if(last==0){
            puts("-1");return 0;
        }
        while(head<tail){
            if(q[tail-1]-tag>r) tail--;
            else break;
        }
        if(head==tail){
            tag=0;
            q[--head]=last;
        }
        else{
            tag++;
            q[--head]=last+tag;
        }
        //printf("%d %d %d\n",l,head,tail);
        ans=max(tail-head,ans);
    }
    printf("%d\n",ans);
    return 0;
}
