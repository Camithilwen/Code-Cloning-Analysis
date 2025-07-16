#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.size()-1;i++){
        if(s.at(i)=='A'&&s.at(i+1)=='C') ans++;
    }
    if(ans>=1) cout << "Yes";
    else cout << "No";
}