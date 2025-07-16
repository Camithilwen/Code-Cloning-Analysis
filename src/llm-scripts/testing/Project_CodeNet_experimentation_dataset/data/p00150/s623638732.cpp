#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool prime[10001];
    memset(prime,0,sizeof(prime));
    for(int i=2;i<sqrt(10001);i++){
        if(!prime[i])for(int j=i*2;j<10005;j+=i)prime[j]=1;
    }
    int n;
    while(cin>>n,n){
        for(int i=n;i>2;i--){
            if(!prime[i]&&!prime[i-2]){
                cout<<i-2<<" "<<i<<endl;
                break;
            }
        }
    }
}