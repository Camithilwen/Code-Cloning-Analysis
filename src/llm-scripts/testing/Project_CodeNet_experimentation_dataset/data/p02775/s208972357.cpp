//#pragma GCC oplmize(2)
#include <bits/stdc++.h>
#define ll long long
#define sc(x) scanf("%lld",&x)
#define scs(x) scanf("%s",x+1)
#define pr(x) printf("%lld\n",x)
#define prs(x) printf("%s\n",x)
using namespace std;
const int maxn=1e7+5;
const int mod=998244353;
const double pi=acos(-1.0);
const double eps = 1e-8;
char s[maxn];
int a[maxn],len;
ll sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    scs(s);
    len=strlen(s+1);
    for(int i=1;i<=len;i++){
        a[i]=s[len-i+1]-'0';
    }
    for(int i=1;i<=len+1;i++){
        if(a[i]==10){
            a[i]-=10;
            a[i+1]++;
        }
        if(a[i]>5){
            sum+=(10-a[i]);
            a[i+1]++;
        }
        else if(a[i]<5){
            sum+=a[i];
        }
        else{
            sum+=5;
            if(a[i+1]>=5){
                a[i+1]++;
            }
        }
    }
    pr(sum);
    return 0;
}