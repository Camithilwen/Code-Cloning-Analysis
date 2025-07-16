#include <bits/stdc++.h>
using namespace std;

long long n;
string s,sw = "SW";

string solve();
string check(string now);

int main() {
    cin >> n >> s;
    cout << solve() << endl;
    return 0;
}

string solve(){
    string ans;
    for(int i = 0;i < 4;++i){
        string now;
        now += sw[i % 2];
        now += sw[i / 2];
        ans = check(now);
        if(ans.size() == n)return ans;
    }
    return "-1";
}

string check(string now){
    for(int i = 2;i < n;++i){
        if(now[i-1] == 'S'){
            if(s[i-1] == 'o')now += now[i-2];
            else now += now[i-2] == 'S'? 'W':'S';
        }
        else {
            if(s[i-1] != 'o')now += now[i-2];
            else now += now[i-2] == 'S'? 'W':'S';
        }
    }
    bool ch = 1;
    if(now[0] == 'S'){
        if(now[1] == now[n-1] && s[0] != 'o')ch = 0;
        if(now[1] != now[n-1] && s[0] == 'o')ch = 0;
    }
    else {
       if(now[1] == now[n-1] && s[0] == 'o')ch = 0;
       if(now[1] != now[n-1] && s[0] != 'o')ch = 0;
    }
    if(now[n-1] == 'S'){
        if(now[n-2] == now[0] && s[n-1] != 'o')ch = 0;
        if(now[n-2] != now[0] && s[n-1] == 'o')ch = 0;
    }
    else {
        if(now[n-2] == now[0] && s[n-1] == 'o')ch = 0;
        if(now[n-2] != now[0] && s[n-1] != 'o')ch = 0;
    }
    if(ch)return now;
    return "";
}