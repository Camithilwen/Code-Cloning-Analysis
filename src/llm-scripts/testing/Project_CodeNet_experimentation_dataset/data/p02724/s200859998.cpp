#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        int n; cin >> n;
        int ans = 0;
        while(n >= 500)
        {
            int x = n/500;
            ans += x*1000;
            n -= (x)*500;
        }
        while(n >= 5)
        {
            int y = n/5;
            ans += y*5;
            n -= y*5;
        }
        cout << ans;
    }    
}