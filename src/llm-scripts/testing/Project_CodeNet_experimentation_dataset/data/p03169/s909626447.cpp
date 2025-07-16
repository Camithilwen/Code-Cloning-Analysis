#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;   
#define ll long long
#define ull unsigned long long
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 
ll mod=1e9+7;
#define PI 3.1415926535897932385
#define inf 9e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
typedef pair<long long, long long> ii;
#define S second
#define F first
ll max(ll a,ll b){if(a>b){return a;}return b;}
ll min(ll a,ll b){if(a<b){return a;}return b;}
#define MAXN 200005
// Comment this out for interactice problem
// #define endl '\n'
// string to integer stoi() Remember: it takes string not character
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
// To compile--> g++ -std=c++0x -o output one.cpp
// To run--> ./output
double dp[305][305][305];

int main()
{ 
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ll n;
    cin>>n;
    ll a[n];
    ll one=0;
    ll two=0;
    ll three=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i]==1){
            one++;
        }
        else if(a[i]==2){
            two++;
        }
        else{
            three++;
        }
    }

    for (int c = 0; c<=n; ++c)
    {
        for (int b = 0; b<=n; ++b)
        {
            for (int a = 0; a<=n; ++a)
            {
                ll k = a+b+c;
                if(k==0){
                    continue;
                }
                if(k>n){
                    continue;
                }
                dp[a][b][c] += (1.0 * n)/k;
                if(a){
                    dp[a][b][c] += (1.0 * a)/k * dp[a - 1][b][c];
                }
                if(b){
                    dp[a][b][c] += (1.0 * b)/k * dp[a + 1][b - 1][c];
                }
                if(c){
                    dp[a][b][c] += (1.0 * c)/k * dp[a][b + 1][c - 1]; 
                }
            }
        }
    }

    cout<<fixed<<setprecision(10)<<dp[one][two][three]<<endl;

    return 0;
}