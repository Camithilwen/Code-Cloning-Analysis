#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <string.h>
#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
using namespace std;
//https://codeforces.com/contest/1213/problems
//https://codeforces.com/contest/1213/submit
ll a[100];
int main(){
    ll n;
    sld(n)
    re(a,0ll);

    for(int i = 0ll; i < 50ll; i ++){
        a[i] = 49ll;
    }
    ll count0 = n/50ll;
    ll count1 = n%50ll;
    for(int i = 0; i < 50; i ++){
        a[i] += count0;
    }
    for(int i = 0; i < count1; i ++){
        a[i] += 50ll;
        for(int j = 0; j < 50; j ++){
            if(i == j){
            }else{
                a[j] --;
            }
        }
    }
    pld(50ll) pn
    for(int i = 0; i < 49; i ++){
        pld(a[i]) pk
    }
    pld(a[49]) pn
    return 0;
}
