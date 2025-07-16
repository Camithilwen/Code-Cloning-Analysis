#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int N;
    string A,B,C;
    cin >> N >> A >> B >> C;
    
    
    int ans = 0;
    for(int i=0;i<N;i++){
        if(A[i]==B[i] && B[i]==C[i]) ans += 0;
        else if(A[i]==B[i]||B[i]==C[i]||A[i]==C[i]) ans++;
        else ans += 2;
        
    }
    
    cout << ans << endl;
    
    return 0;
}
