#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int Max=1e6+7;
ll a[Max]; int n,k;

int main(){
    ios::sync_with_stdio(0);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
    ll ans=0;
    //cout<<"OK"<<endl;
    if(a[1]>=0) ans=a[k];
    else if(a[n]<=0) ans=-a[n-k+1];
    else{
        int index=0;
        for(int i=1; i<=n; i++){
            if(a[i]>=0) {
                index=i; break;
            }
        }

        ans=0x3f3f3f3f;
        for(int i=index; i<index+k && i<=n; i++){
            ll tot=abs(a[i]);

            if(i-index+1<k){
               tot+=abs(a[i]);
               if(i-k+1>=1){
                    tot+=abs(a[i-k+1]);
                    //cout<<tot<<endl;
                    ans=min(tot,ans);
               }
            }else{
                //cout<<tot<<endl;
                ans=min(tot,ans);
            }
        }
        index--;
        for(int i=index; i>=1 && i>=index-k+1; i--){
            ll tot=abs(a[i]);
            if(index-i+1<k){
                tot+=abs(a[i]);
                if(k+i-1<=n){
                    tot+=abs(a[k+i-1]);
                    ans=min(ans,tot);
                }
            }
            else{
                ans=min(ans,tot);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}