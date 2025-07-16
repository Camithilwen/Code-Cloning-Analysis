#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=2e9;
    for(int i=0;i<n;i++){
        int cnt=0;
        while(a[i]%2==0){
            cnt++;
            a[i]/=2;
        }
        ans=min(cnt,ans);
    }
    cout<<ans<<endl;
    return 0;
}