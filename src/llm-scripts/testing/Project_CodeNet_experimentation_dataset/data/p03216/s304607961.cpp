#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q; string s;
    cin >> n >> s >> q;

    for(int i=0; i<q; i++){
        int k;
        cin >> k;

        long long int d = 0, m = 0, dm = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'D') d += 1;
            if(s[i] == 'M'){ m += 1; dm += d; }

            if(i >= k){
                if(s[i-k] == 'D'){ d -= 1; dm -= m; }
                if(s[i-k] == 'M') m -= 1;
            }

            if(s[i] == 'C') ans += dm;
        }
        cout << ans << endl;
    }
    return 0;
}