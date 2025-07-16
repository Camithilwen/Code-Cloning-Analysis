#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    long l, r;
    cin>>l >>r;
    long ans=2019;
    for(long i=l+1;i<=r;i++){
        for(long k=l;k<i;k++){
            long a=(i*k)%2019;
            ans=min(ans,a);
            if(ans==0){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
}