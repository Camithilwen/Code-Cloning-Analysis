#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    string ans="";
    while(N){
        N--;
        int r=N%26;
        N=N/26;
        ans+='a'+r;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
