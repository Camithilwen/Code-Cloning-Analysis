#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
#define ll long long
char a[N];
int main(){
    int n,q,k;
    scanf("%d\n",&n);
    scanf("%s",a);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&k);
        ll nowd=0,nowm=0,cnt=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            if(i-k>=0&&a[i-k]=='D'){
                nowd--;
                cnt-=nowm;
            }
            else if(i-k>=0&&a[i-k]=='M'){
                nowm--;
            }
            if(a[i]=='D')nowd++;
            if(a[i]=='M'){
                nowm++;
                cnt+=nowd;
            }
            if(a[i]=='C')sum+=cnt;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
