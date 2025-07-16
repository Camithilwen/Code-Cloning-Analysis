#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=1;i<s.size();i++){
        if(1<i && s[i-2]==s[i]){
            cout << i-1 << " " << i+1 << endl;
            return 0;
        }

        if(s[i-1]==s[i]){
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}