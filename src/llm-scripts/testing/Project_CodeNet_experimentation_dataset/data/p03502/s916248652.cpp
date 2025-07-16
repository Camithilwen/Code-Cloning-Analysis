#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    int N;
    cin>>N;
    int P=N;
    int S;
    bool a=true;
    while(a==true){
        if(N==0){
            a=false;
        }
        else{
            S+=N%10;
            N-=N%10;
            N/=10;
        }
    }
    if(P%S==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

