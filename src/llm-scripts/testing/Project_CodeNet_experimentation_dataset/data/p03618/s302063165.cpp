#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    string s;
    cin >> s;

    map<char, long long> T;
    for(long long i = 0; i < s.size(); i++){
        if(T.find(s[i]) == T.end()) T[s[i]] = 1;
        else T[s[i]]++;
    }

    map<char, long long>::iterator it;
    long long ans = 0;
    for(it = T.begin(); it != T.end(); it++){
        if(it->second >= 2) ans += it->second*(it->second-1)/2;
    }

    cout << 1+s.size()*(s.size()-1)/2 - ans << endl;
    return 0;
}