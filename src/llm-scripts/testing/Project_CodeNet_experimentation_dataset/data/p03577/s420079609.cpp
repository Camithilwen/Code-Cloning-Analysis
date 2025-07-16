#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i+8 < s.length(); i++) ans += s[i];
    cout << ans << endl;
    return 0;
}