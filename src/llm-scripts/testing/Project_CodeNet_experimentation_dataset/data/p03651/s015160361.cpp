#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n;
    ll k;
    cin >> n >> k;

    ll a[n];
    int flag = 0;
    ll max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(max < a[i]){
            max = a[i];
        }
        if(a[i] == k){
            flag = 1;
        }
    }

    if(flag == 0){
        ll b = a[0];
        for(int i = 1; i < n; i++){
            b = gcd(b, a[i]);

            if(b == 1){
                break;
            }
        }

        if(k % b == 0 && k <= max){
            flag = 1;
        }
    }

    if(flag == 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << "POSSIBLE" << endl;
    }
}