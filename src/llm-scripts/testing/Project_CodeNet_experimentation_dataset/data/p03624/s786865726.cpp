#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    vector<int> alp(26, 0);
    for(char d : s){
        alp[d - 'a'] = 1;
    }
    bool f = true;
    for(int i = 0; i < 26; i++){
        if(alp[i] == 0){
            f = false;
            cout << char(i + 'a') << endl;
            break;
        }
    }
    if(f) puts("None");
}