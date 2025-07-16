#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int t;
    cin>>t;
    long long int ans = 0, max = t;
    for(int i = 1; i < n; i++) {
        cin>>t;
        if(t < max) {
            ans += max-t;
        }
        else if(t > max) {
            max = t;
        }
    }
    cout<<ans<<endl;
    return 0;
}