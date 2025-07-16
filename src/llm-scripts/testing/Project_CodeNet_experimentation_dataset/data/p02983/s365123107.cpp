#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;
    long long ans=3000;
    if(r-l>=2200)cout<<0<<endl;
    else{
        for(long long i=l;i<=r-1;i++){
            for(long long j=i+1;j<=r;j++){
                long long tmp=(i*j)%2019;
                ans=min(ans,(i*j)%2019);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}