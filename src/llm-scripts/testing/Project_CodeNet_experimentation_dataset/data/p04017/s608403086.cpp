#include <bits/stdc++.h>
const int N=100005,M=20;
using namespace std;
int n,L,q,ar[N],nx[M][N];
int calc(int i){
    int l=i,r=n,ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(ar[m]-ar[i]<=L){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return ans;
}
int kth(int cur,int k){
    for(int i=M-1;i>=0;i--){
        if(k>=(1<<i)){
            k-=(1<<i);
            cur=nx[i][cur];
        }
    }
    return cur;
}
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    cin>>L>>q;
    for(int i=1;i<=n;i++)nx[0][i]=calc(i);
    for(int i=1;i<M;i++){
        for(int j=1;j<=n;j++){
            nx[i][j]=nx[i-1][nx[i-1][j]];
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        if(a>=b)swap(a,b);
        int l=1,r=n,ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            //cout<<a<<' '<<m<<' '<<kth(a,m)<<'\n';
            if(kth(a,m)>=b){
                ans=m;
                 r=m-1;
            }else{

                l=m+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
