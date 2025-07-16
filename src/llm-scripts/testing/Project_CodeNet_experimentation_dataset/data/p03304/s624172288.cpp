#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    double n,m,d;cin >>n>>m>>d;
    double p;
    if(d==0){
        p=1/n;
    }
    else {
        p=2*(n-d)/(n*n);
    }
//    cout <<p<<endl;
    p*=(m-1);
    cout <<setprecision(20)<<p<<endl;
    return 0;
}

