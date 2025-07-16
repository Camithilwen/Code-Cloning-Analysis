#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
LL n,i,maxi,mini=OO;
scanf("%lld",&n);
for(i=1;i*i<=n;++i){
    if(n%i==0){
        LL num1=i,num2=n/i,counter1=0,counter2=0;
        while(num1){
            num1/=10;
            counter1++;
        }
        while(num2){
            num2/=10;
            counter2++;
        }
        maxi=max(counter1,counter2);
        mini=min(mini,maxi);
    }
}
printf("%lld",mini);


    return 0;
}
