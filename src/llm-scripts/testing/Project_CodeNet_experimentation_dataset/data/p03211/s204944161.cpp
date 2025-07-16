#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int ans = 753;
    for(int i = 0; i <= S.size()-3; ++i){
        int buf = (S[i]-'0')*100 + (S[i+1]-'0')*10 + (S[i+2]-'0');
        ans = min(ans, abs(buf-753));
    }
    cout << ans << endl;
    return 0;
}