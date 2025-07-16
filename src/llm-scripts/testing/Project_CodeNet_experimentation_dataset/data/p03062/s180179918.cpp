#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    bool f=0;
    int n;
    long long a,b=0ll,x=2e9;
    sc1(n);
    rep(i,n){
        scanf("%lld",&a);
        if (a<0) f=f^1;
        b+=abs(a);
        x=min(x,abs(a));
    }
    printf("%lld\n",f?b-x*2:b);
    return 0;
}
