#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAX=1e4+10;
const int mod=1e9+7;

void fun(int *cnt,int n){
    for(int i=2;i<=n;i++){
        while(n%i==0){
            cnt[i]++;
            n/=i;
        }
    }
}

ll solve(int n){
    int cnt[1001]={0};
    ll ans=1;
    for(int i=2;i<=n;i++){
        fun(cnt,i);
    }
    for(int i=2;i<=1000;i++){
        ans=ans*(cnt[i]+1)%mod;
    }
    return ans;
}

int main(){
    int n;
    while(cin>>n){
        cout<<solve(n)<<endl;
    }
    return 0;
}
