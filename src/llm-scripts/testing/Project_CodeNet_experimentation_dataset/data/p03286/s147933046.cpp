#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N;
    cin >> N;
    if(N==0){
        cout << 0 << endl;
        return 0;
    }
    string S = "";
    while(N!=0){
        if(N%2==0){
            if(N<0){
                N*=(-1);
                N/=2;
            }else{
                N/=2;
                N*=(-1);
            }
            S+='0';
            continue;
        }
        if(N<0){
            N*=(-1);
            N+=1;
            N/=2;
        }else{
            N/=2;
            N*=(-1);
        }
        S+='1';
    }
    reverse(S.begin(),S.end());
    cout << S << endl;
    return 0;
}