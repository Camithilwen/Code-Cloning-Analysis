#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
int main(){
    int n;
    cin >> n;
    int a;
    long long int ans=1;
    int r=0; int g=0; int b=0;
    for(int i=0;i<n;i++){
        cin >> a;
        ans *= ((a==r)+(a==g)+(a==b));
        ans %=mod;
        if(a==r)r++;
        else if(a==g)g++;
        else b++;
    }
    cout << ans;
}