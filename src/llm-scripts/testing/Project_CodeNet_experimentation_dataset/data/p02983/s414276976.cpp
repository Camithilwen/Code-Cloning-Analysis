#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int l,r;
    cin >> l >> r;
    const int num = 2019;
    int comp = INT_MAX;
    long long ans = 0;
    for(long long i=l; i<=r; i++){
        for(long long j=l; j<i; j++){
            ans = ((i%num) * (j%num))%num;
            if(ans < comp){
                comp = ans;
            }
            else if(ans == 0){
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << comp << endl;
}