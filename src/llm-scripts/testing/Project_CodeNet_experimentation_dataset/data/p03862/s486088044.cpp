#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int main(){
    int n,x,a;
    while(~scanf("%d%d%d",&n,&x,&a)){
        ll ans=0;
        if(a>x)
            ans+=a-x,a=x;
        while(--n){
            int b;
            scanf("%d",&b);
            if(a+b>x)
                ans+=a+b-x,a=x-a;
            else
                a=b;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
