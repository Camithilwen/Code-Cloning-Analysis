#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    ll n;
    cin >> n;
    cout << 0 << endl;
    vector<string> ans(n);
    cin >> ans[0];
    if(ans[0] == "Vacant"){
        return 0;
    }
    cout << n-1 << endl;
    cin >> ans[n-1];
    if(ans[n-1] == "Vacant"){
        return 0;
    }
    ll right = n-1;
    ll left = 0;
    while(right-left > 1){
        ll mid = (right+left)/2;
        cout << mid << endl;
        cin >> ans[mid];
        if(ans[mid] == "Vacant") return 0;
        else{
            if((right-mid)%2 == 0 && ans[mid] != ans[right]){
                left = mid;
            }
            else if((right-mid)%2 == 1 && ans[mid] == ans[right]){
                left = mid;
            }
            else if((mid-left)%2 == 0 && ans[mid] != ans[left]){
                right = mid;
            }
            else if((mid-left)%2 == 1 && ans[mid] == ans[left]){
                right = mid;
            }
        }
    }

}