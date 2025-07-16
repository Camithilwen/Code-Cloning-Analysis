#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    long long x;
    cin>>x;

    long long thousand=(x/500)*1000;

    long long rest=(x%500)/5*5;;

    long long ans=thousand+rest;
    cout<<ans<<endl;
}


