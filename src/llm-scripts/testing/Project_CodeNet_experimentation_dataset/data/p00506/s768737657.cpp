#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b%a ? gcd(b%a,a) : a;}
int main(){
    int N;
    cin>>N;
    int a,b,c;
    cin>>a>>b;
    if(N==3) cin>>c;
    int tmp=gcd(a,b);
    if(N==3) tmp=gcd(tmp,c);
    for(int i=1;i<=tmp;i++){
        if(tmp%i==0) cout<<i<<endl;
    }
    return 0;
}

