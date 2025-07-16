#include <bits/stdc++.h>
using namespace std;

struct base{
    #define type long long
    #define log 60
    type d[log+1] = {};
    bool insert(type x){
        for(int i=log; ~i; i--) if((x>>i)&1){
            if(!d[i]){
                d[i] = x;
                break;
            }
            x ^= d[i];
        }
        return x;
    }
    type max(){
        type ret = 0;
        for(int i=log; ~i; i--)
            if((ret^d[i]) > ret)
                ret ^= d[i];
        return ret;
    }
};

int main()
{
    int n;
    scanf("%d",&n);

    long long xo = 0;
    vector <long long> v(n) ,prt(60 ,0);
    for(auto&a : v){
        scanf("%lld",&a) ,xo ^= a;
        for(int b=0; b<60; b++)
            prt[b] ^= (a>>b)&1;
    }

    base h;
    for(auto&a : v){
        for(int b=0; b<60; b++)
            a &= ~(prt[b]<<b);
        h.insert(a);
    }

    long long mx = h.max();
    printf("%lld\n",(xo^mx)+mx);
}
