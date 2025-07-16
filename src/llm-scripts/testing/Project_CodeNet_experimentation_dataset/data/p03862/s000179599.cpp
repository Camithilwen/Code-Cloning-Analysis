#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
long long int n,x,ans=0;
cin>>n>>x;
vector<long long int>a(10000000);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n-1;i++){
    if((a[i]+a[i+1])>x){
        ans+=(a[i]+a[i+1]-x);
        a[i+1]=a[i+1]-(a[i]+a[i+1]-x);
        if(a[i+1]<0){
            a[i]+=a[i+1];
            a[i+1]=0;
        }
    }
}
cout<<ans<<endl;
    return 0;
}
