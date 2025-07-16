#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

long long int gcd(long long int a,long long int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}
long long int fac(long long int n){
    if(n==0){
        return 1;
    }
    else{
        return n*(fac(n-1))%1000000007;
    } 
}

int main(){
    long long int n,k,ans=0;
    cin>>n;
    ans+=2*((n-1)/11);
    if(n%11<7&&n%11>0){
        ans++;
    }
    else{
        ans++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}