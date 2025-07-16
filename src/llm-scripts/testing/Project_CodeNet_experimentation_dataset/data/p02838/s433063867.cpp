#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 1001001001;

long long pow2[60];
void init_pow2(){
    pow2[0] = 1;
    for(int i=1; i<60; i++){
        pow2[i]  = 2*pow2[i-1];
        pow2[i] %= MOD;
    }
    return;
}

int main(){
    init_pow2();
    
    int n;cin>>n;
    vector<long long> a(n);
    vector<long long> count(60, 0);
    
    long long s = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        s += a[i];
        s %= MOD;
        for(int j=0; j<60; j++){
            if((a[i]>>j)&1)count[j]++;
        }
    }
    
    s *= n-1;
    s %= MOD;
    
    for(int j=0; j<60; j++){
        long long t=1;
        t *= count[j]*(count[j]-1)/2;
        t %= MOD;
        t *= 2 * pow2[j];
        t %= MOD;
        s += MOD - t;
        s %= MOD;
    }
    
    cout << s << endl;
    
    return 0;
}