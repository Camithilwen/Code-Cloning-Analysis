#include <stdio.h>
int n,k,i,j,p,num[5040],c[4],card[10],ans;
void set(int x){
    int i,j;
    if (x==k) {
        for (i=0; i<k; i++) {
            num[p]=num[p]*10;
            if (card[c[i]]>=10) {
                num[p]=num[p]*10;
            }
            num[p]+=card[c[i]];
        }
        p++;
        return;
    }
    for (i=0; i<n; i++) {
        int flag=1;
        for (j=0; j<x; j++) {
            if (c[j]==i) {
                flag=0;
                break;
            }
        }
        if (flag) {
            c[x]=i;
            set(x+1);
        }
    }
    return;
}
int main(){
    while (1) {
        scanf("%d%d",&n,&k);
        if (n==0&&k==0) {
            return 0;
        }
        for (i=0; i<n; i++) {
            scanf("%d",&card[i]);
        }
        for (i=0; i<5040; i++) {
            num[i]=0;
        }
        p=0;
        set(0);
        ans=0;
        k=p;
        while (k>0) {
            for (i=0; i<p; i++) {
                if (num[i]!=-1) {
                    ans++;
                    k--;
                    for (j=i+1; j<p; j++) {
                        if (num[i]==num[j]) {
                            k--;
                            num[j]=-1;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}