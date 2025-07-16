#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, t0;
    cin >> n >> t0;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];

    long long int ans = t0;

    for(int i = 1; i < n; i++){
        if(t[i]-t[i-1] >= t0) ans += t0;
        else ans += t[i]-t[i-1];
    }
    
    cout << ans << endl;
    return 0;
}