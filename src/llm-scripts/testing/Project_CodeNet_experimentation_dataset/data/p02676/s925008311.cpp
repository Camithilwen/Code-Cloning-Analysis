#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    string ss;
    cin>>k>>s;
    if(s.length()>k){
        for(int i=0; i<k; i++){
            ss += s[i];
        }
        ss+="...";
    }
    else {
        ss =s;
    }
    cout<<ss;
    return 0;
}
