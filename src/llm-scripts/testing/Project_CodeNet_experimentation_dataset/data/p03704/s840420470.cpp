#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set> 
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define db double
#define inf 301
#define INF (int)1e8 
#define mod (int)(1e9+7)
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;
 
const int lim=18;
ll P10[20],cnt[20];
 
void pre_work(void){
    P10[0]=1LL;
    for (int i=1;i<=lim;i++){
        P10[i]=P10[i-1]*10LL;
    }
    for (int i=0;i<=9;i++){
        for (int j=0;j<=9;j++){
            cnt[i-j+10]++;
        }
    }
    return;
}
 
ll D,ans=0;
 
void dfs(int step,ll x,ll sum,int len){
    if (step>len/2-1){
        if (len&1){
            sum*=10LL;
        }
        if (x==D){
            ans+=sum;
        }
        return;
    }
    ll now=-9;
    while (now<=9 && x+now*(P10[len-step-1]-P10[step])<=D){
        now++;
    }
    now--;
    dfs(step+1,x+now*(P10[len-step-1]-P10[step]),sum*(cnt[now+10]-(step==0 && now>=0)),len);
    now++;
    if (now>9){
        return;
    }
    dfs(step+1,x+now*(P10[len-step-1]-P10[step]),sum*(cnt[now+10]-(step==0 && now>=0)),len);
    return;
}
 
int main(){
    rd(D)
    pre_work();
    for (int i=1;i<=18;i++){
        dfs(0,0LL,1LL,i);
    }
    printf("%lld\n",ans);
    return 0;
}
