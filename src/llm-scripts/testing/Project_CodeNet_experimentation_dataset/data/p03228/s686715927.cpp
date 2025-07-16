#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll a,b, k; cin >> a >> b >> k;
    for(int i = 0; i < k; i++){
        if(i %2 == 0){
            a/=2; b += a;
        }else{
            b/=2; a += b;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}