
/**
 *    author        : Sudipta Banik Trisha 
 *    created       : September 10, 2020 5:11 PM
 *    Problem Name  : D - Dice in Line
 *    Problem Limit : 2000 ms , 1024 MB
 *    Problem Url   : https://atcoder.jp/contests/abc154/tasks/abc154_d
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    ll n,k;
    cin >> n >> k;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin >> v[i];
        v[i] = 1 + v[i];
    }
    for(ll i=1; i<n; i++){
        v[i] = v[i-1] + v[i];
    }
    
    long double mxprob = (long double)v[k-1];
    for(int i=k; i<n; i++) {
        mxprob = max(mxprob , (long double)(v[i] - v[i-k]));
    }

    mxprob = mxprob / (long double)2.0;
    cout << fixed << setprecision(12) << mxprob << endl;

    return 0 ;
}
