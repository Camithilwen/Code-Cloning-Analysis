#include <bits/stdc++.h>
using namespace std;
// ascii 97~122

int main(){
    string s;
    getline(cin,s);
    vector<bool> vec(26);
    for(int i=0; i<26; i++){
        vec.at(i) = false;
    }
    char c;
    int n = s.size();
    for(int i=0; i<n; i++){
        c = s.at(i);
        vec.at((int)(char)c - 'a') = true;
    }
    for(int i=0; i<26; i++){
        if(vec.at(i)==false){
            cout << (char)(i +'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}