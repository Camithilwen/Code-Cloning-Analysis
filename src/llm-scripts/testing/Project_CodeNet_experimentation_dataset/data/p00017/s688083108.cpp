#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
 
int main() {
    string s;
    while(getline(cin,s)) {
        string t;
        rep(j,0,26) {
            t.clear();
            rep(i,0,s.length()) {
                if('a' <= s[i] && s[i] <= 'z') {
                    int val = (s[i] - 'a' + j) % 26;
                    t += ('a' + val);
                }
                else t += s[i];
            }
            if(t.find("this") != string::npos) break;
            else if(t.find("the") != string::npos) break;
            else if(t.find("that") != string::npos) break;
        }
        cout << t << endl;
    }
    return 0;
}