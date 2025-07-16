#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

bool is_integer(double x){
    return std::floor(x) == x;
}

int main(){
    ll n; cin >> n;

    while(true){
        if(is_integer(sqrt(n))){
            put(n);
            return 0;
        }
        n--;
    }
}