#include<bits/stdc++.h>
using namespace std;
map<long long int,long long int> mp;
int main(){
    int n;
    long long int m;
    cin >> n >> m;
    long long int a[n];
    long long int sum =0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        sum %= m;
        mp[sum]++;
    }
    long long int ans=0;
    for(auto u:mp){
        if(u.first==0LL)ans += u.second;
        ans += u.second*(u.second-1)/2;
    }
    cout << ans << endl;
}