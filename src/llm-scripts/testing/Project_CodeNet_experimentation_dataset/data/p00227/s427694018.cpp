#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n,m){

        int yasai[1024]={0};
        for(int i = 0;i < n; i++){
            scanf("%d",&yasai[i]);
        }
        sort(yasai,yasai+n);
        for(int i = n;i >= 0; i-=m){
            yasai[i] = 0;
        }
        int ans=0;
        for(int i = 0;i < n; i++){
            ans += yasai[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}