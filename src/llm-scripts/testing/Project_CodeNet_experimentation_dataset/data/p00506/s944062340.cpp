#include <stdio.h>
#include <set>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
    int n,ans,temp;
    set<long long int> s;
    scanf("%d%d",&n,&ans);
    n--;
    while(n--){
        scanf("%d",&temp);
        ans=gcd(ans,temp);
    }
    for(long long int i=1;i*i<=ans;i++)if(ans%i==0){
            s.insert(i);
            s.insert(ans/i);
    }
    for(auto u:s)printf("%lld\n",u);
}
