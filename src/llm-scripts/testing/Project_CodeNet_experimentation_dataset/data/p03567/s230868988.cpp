#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int ok=0;
    for (int i=0;i+1<S.size();++i)
        if (S[i]=='A'&&S[i+1]=='C') ok=1;
    cout << (ok?"Yes":"No") << '\n';
}