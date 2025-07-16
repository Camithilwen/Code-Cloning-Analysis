#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N];
int F(int a,int b){
    string x = to_string(a);
    string y = to_string(b);
    return max(x.length(),y.length());
}
int32_t main(){
    fast;
    int n , ans = 1e12; cin >> n ;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i==0){
            int a = i ,b = n/i;
            ans = min(ans,F(a,b));
        }
    }
    cout << ans << endl;
    return 0;
}