#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    if(n==0) {
        cout << 0;
        return 0;
    }

    vector<vector<ll>> a(33,vector<ll> (2));
    a[0][0] = 1;
    a[0][1] = 0;

    ll m = 1;

    for(int i=1;i<33;i++){
        m*=-2;
        if(m>0){
            a[i][0] = a[i-1][0] + m;
            a[i][1] = a[i-1][1];
        }else{
            a[i][1] = a[i-1][1] + m;
            a[i][0] = a[i-1][0];
        }
    }
    ll tmp = n;
    vector<int> ans(33,0);
    for(int i=32;i>0;i--){
        if(tmp>0){
            if(a[i][0]>=tmp&&tmp>a[i-1][0]){
                ans[i] = 1;
                tmp = tmp - m;
            }else{
                ans[i] = 0;
            }
        }else{
            if(a[i][1]<=tmp&&tmp<a[i-1][1]){
                ans[i] = 1;
                tmp = tmp - m;
            }else{
                ans[i] = 0;
            }
        }
        m /= (-2);
    }
    if(tmp == 1){
        ans[0] = 1; 
    }else{
        ans[0] = 0;
    }

    bool flag = false;

    for(int i=32; i >= 0; i--){
        if(!flag){
            if(ans[i]==1){
                cout << ans[i];
                flag = true;
            }
        }else{
            cout << ans[i];
        }
    }


    return 0;
}