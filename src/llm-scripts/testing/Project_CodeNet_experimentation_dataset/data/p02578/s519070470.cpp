#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;

    int h;
    ll ans = 0;
    cin >> h;
    for(int i=0;i<n-1;i++){
        int nh;
        cin >> nh;
        if(nh>=h) h = nh;
        else ans += (h-nh);
    }
    cout << ans << endl;
    return 0;
}