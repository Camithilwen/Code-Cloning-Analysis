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
#define UB upper_bound
#define LB lower_bound
const int NUM = 2e5 + 5;
const int N = 301;
double dp[N][N][N];
// dp[x][y][z] = x 3s, y 2s, z 1s and (n - x - y - z) zeros
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        int n; cin >> n;
        int cnt[4] = {0};
        FOR(i,0,n){
            int x; cin >> x;
            cnt[x]++;
        }
        dp[0][0][0] = 0.0;
        FOR(x,0,n+1){
            FOR(y,0,n+1){
                FOR(z,0,n+1){
                    int zeros = n - (x+y+z);
                    if(zeros == n) continue;
                    if(zeros < 0) continue;
                    double res = 1.0;
                    // if I pick 3
                    if(x > 0) res += (1.0 * x/n) * dp[x-1][y+1][z];
                    // if I pick 2
                    if(y > 0) res += (1.0 * y/n) * dp[x][y-1][z+1];
                    // if I pick 1
                    if(z > 0) res += (1.0 * z/n) * dp[x][y][z-1];
                    res = res/(1 - 1.0*zeros/n);
                    dp[x][y][z] = res;
                }
            }
        }
        cout << fixed << setprecision(10);
        cout << dp[cnt[3]][cnt[2]][cnt[1]];
    }   
}