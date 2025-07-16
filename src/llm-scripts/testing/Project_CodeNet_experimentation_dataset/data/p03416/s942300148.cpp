#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    int ans = 0;
    cin >> a >> b;
    string s;
    string r_s = "";
    for (int num = a; num < b + 1; num ++){
        r_s = "";
        s = to_string(num);
        for (int i = 0; i < s.size(); i ++){
            r_s += s[s.size() - 1 - i];
        }
        if (s == r_s){
            ans += 1;
        }
    }
    cout << ans << endl;
}