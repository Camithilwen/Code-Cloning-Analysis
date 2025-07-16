#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,a[105],ans=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(x>a[i] && i!=n-1){
            ans++;
            x-=a[i];
        }
        else if(a[i]==x){
            ans++;
            x-=a[i];
        }
    }
    cout<<ans<<endl;
    return(0);
}