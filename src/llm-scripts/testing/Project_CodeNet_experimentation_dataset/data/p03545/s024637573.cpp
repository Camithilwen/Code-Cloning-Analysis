#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    string s; cin >> s;
    for(int bit=0; bit<(1<<3); bit++){
        string str = "";
        str += s[0];
        int cnt = s[0] - '0';

        if(bit & (1<<0)){
            cnt += s[1] - '0';
            str += "+";
        }else{
            cnt -= s[1] - '0';
            str += "-";
        }
        str += s[1];

        if(bit & (1<<1)){
            cnt += s[2] - '0';
            str += "+";
        }else{
            cnt -= s[2] - '0';
            str += "-";
        }
        str += s[2];

        if(bit & (1<<2)){
            cnt += s[3] - '0';
            str += "+";
        }else{
            cnt -= s[3] - '0';
            str += "-";
        }
        str += s[3];
        if(cnt == 7){
            str += "=7";
            cout << str << endl;
            break;
        }
    }
}