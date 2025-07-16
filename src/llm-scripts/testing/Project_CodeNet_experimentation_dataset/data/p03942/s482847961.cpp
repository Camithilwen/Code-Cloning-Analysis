#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, A[1010000], B[1010000], cnt;
vector<int>E[26];
char p[1010000], q[1010000];
int main(){
    int i, pv, ck = 0, res = 0;
    scanf("%d",&n);
    scanf("%s",p+1);
    scanf("%s",q+1);
    for(i=1;i<=n;i++){
        E[p[i]-'a'].push_back(i);
        if(p[i]!=q[i])ck = 1;
    }
    if(!ck){
        printf("0\n");
        return 0;
    }
    pv = n;
    for(i=n;i>=1;i--){
        if(q[i]!=q[i-1]){
            pv = min(pv, i);
            int x = q[i]-'a';
            int t = lower_bound(E[x].begin(), E[x].end(), pv + 1) - E[x].begin();
            if(!t){
                printf("-1\n");
                return 0;
            }
            B[++cnt] = i;
            A[cnt] = E[x][t-1];
            pv = E[x][t-1] - 1;
        }
    }
    for(i=1;i<=cnt/2;i++)swap(A[i],A[cnt+1-i]),swap(B[i],B[cnt+1-i]);
    cnt++;
    A[cnt]=B[cnt]=n+1;
    for(i=1;i<=cnt;i++) A[i]-=i, B[i]-=i;
    for(i=1;i<=cnt;i++){
        int t = lower_bound(A+1,A+cnt+1,B[i]) - A;
        res = max(res, t - i);
    }
    printf("%d\n",res+1);
}