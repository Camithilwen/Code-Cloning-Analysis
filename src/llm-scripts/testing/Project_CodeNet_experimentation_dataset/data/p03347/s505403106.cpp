#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    int n;
    cin>>n;
    long long a[n+1];
    rep2(i,n){
        cin>>a[i];
    }
    
    a[0]=-1;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]+1){
            cout<<"-1"<<endl;
            return 0;
        }        
    }
    long long ans=0;

    for(int i=2;i<=n;i++){
        if(a[i-1]+1==a[i]){
            ans++;
            //cout<<"?";
        }
        else{
            ans+=a[i];
            //cout<<"!";
        }
    }
    cout<<ans<<endl;
    return 0;

}
/*


*/
