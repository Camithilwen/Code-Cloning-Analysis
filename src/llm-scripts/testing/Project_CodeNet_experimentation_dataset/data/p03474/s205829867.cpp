#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    string s;
    cin >> a >> b >> s;
    string ans="Yes";
    for(int i=0; i<a; i++){
        if(0>s.at(i)-'0'||s.at(i)-'0'>9) ans="No";
    }
    if(s.at(a)!='-') ans="No";
    for(int i=0; i<b; i++){
        if(0>s.at(i+a+1)-'0'||s.at(i+a+1)-'0'>9) ans="No";
    }
    cout << ans << endl;
}