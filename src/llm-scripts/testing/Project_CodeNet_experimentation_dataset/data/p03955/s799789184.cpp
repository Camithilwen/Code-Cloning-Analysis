#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
int val[3][N],p[N],inv[N],cir[2];
void fail(){puts("No");exit(0);}
int main(){
    scanf("%d",&n);
    for(int t=0;t<3;t++)
        for(int i=1;i<=n;i++)
            scanf("%d",&val[t][i]);
    for(int i=1;i<=n;i++){
        p[i]=(val[1][i]+1)/3;
        int temp[3]={val[0][i],val[1][i],val[2][i]};
        sort(temp,temp+3);
        for(int j=0;j<3;j++) if(temp[j]!=p[i]*3+j-2) fail();
        if(val[1][i]%3!=2) fail();
        inv[i]=val[0][i]>val[1][i] ? 1:0;
    }
    for(int i=1;i<=n;i++) if((p[i]-i)%2!=0) fail();
    for(int i=2;i<=n;i++) inv[i%2]+=inv[i];
    for(int i=1;i<=n;i++)
        if(p[i]!=0){
            cir[i%2]++;
            for(int j=i,last;j!=0;last=j,j=p[j],p[last]=0);
        }
    for(int i=0;i<=1;i++) if(((n/2+(n&i))-cir[i])%2!=inv[i^1]%2) fail();
    return puts("Yes"),0;
}