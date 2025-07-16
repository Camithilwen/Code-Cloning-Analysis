#include<iostream>
using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    int a[n];
    long long ans=0;
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]-a[i-1]>t){
            ans+=t;
        }else{
            ans+=a[i]-a[i-1];
        }
    }
    ans+=t;
    cout<<ans<<endl;
    return 0;
}