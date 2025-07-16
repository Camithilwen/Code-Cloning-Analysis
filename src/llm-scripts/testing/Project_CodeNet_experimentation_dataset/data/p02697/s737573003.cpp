#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int MOD = 998244353;
const int N = 2*1e5;

int main(){
    AC
    int n, m;
    cin>>n>>m;
    if(n%2!=0){
        for(int i=1; i<=m; i++){
            cout<<i<<" "<<n-i<<endl;
        }
    }
    else{
        int odd = (m+1)/2;
        for (int i = 1; i<=odd; i++)
            cout << i << ' ' << n-i+1 << '\n';
        for (int i = odd+1; i<=m; i++)
            cout << i << ' ' << n-i << '\n';
    }
}