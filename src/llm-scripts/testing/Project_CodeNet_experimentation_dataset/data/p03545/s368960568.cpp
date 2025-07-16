#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    for(int bit=0; bit<(1<<3); bit++){
        int svn = s[0]-'0';
        for(int i=0; i<3; i++){
            if(bit & (1<<i)) svn += s[i+1]-'0';
            else svn -= s[i+1]-'0';
        }
        if(svn == 7){
            for(int i=0; i<3; i++){
                if(bit & (1<<i)) s.insert(2*i+1, "+");
                else s.insert(2*i+1, "-");
            }
            s += "=7";
            goto SKIP;
        }
    }
SKIP:
    cout << s << '\n';
    return 0;
}