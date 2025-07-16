#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int a;
int ans=1000000000;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        int k=0;
        while(a%2==0){
            a=a/2;
            k++;
        }
        ans=min(ans,k);
    }
    cout<<ans<<endl;
    
}
