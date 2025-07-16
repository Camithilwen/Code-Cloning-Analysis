#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    while(1){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0) break;
        int a[1001] = {0};
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(i % m == 0)continue;
            sum += a[i];
        }
        printf("%d\n",sum);
    }

    return 0;
}