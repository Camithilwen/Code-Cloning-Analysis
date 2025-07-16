#include <cstdio>
using namespace std;
int main(void){
    int a[1000],b[1000],c[1000],i,j,r[1000],n,ans[303],abc;
    for(j=0;j<6;j++){
        scanf("%d%d%d%d",&a[0],&b[0],&c[0],&n);
        if(a[0]==0) return 0;
        abc=a[0]+b[0]+c[0];
        for(i=0;i<=abc+1;i++) ans[i]=2;
        for(i=0;i<n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&r[i]);
        for(i=0;i<n;i++) if(r[i]){
            ans[a[i]]=ans[b[i]]=ans[c[i]]=1;
        }
        for(i=0;i<n;i++) if(r[i]-1) if(ans[a[i]]+ans[b[i]]+ans[c[i]]==4&&(ans[a[i]]==1||ans[b[i]]==1)){
            if(ans[a[i]]-1){
                ans[a[i]]=0;
            }else if(ans[b[i]]-1){
                ans[b[i]]=0;
            }else ans[c[i]]=0;
        }
        for(i=1;i<=abc;i++) printf("%d\n",ans[i]);
    }
}