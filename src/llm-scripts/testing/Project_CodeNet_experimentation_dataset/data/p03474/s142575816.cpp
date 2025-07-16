#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    string ans = "Yes";
    for(int i = 0; i < a; i++){
        if(!(s[i] >= '0' && s[i] <= '9')) ans = "No";
    }
    if(s[a] != '-') ans = "No";
    for(int i = a+1; i < a+b+1; i++){
        if(!(s[i] >= '0' && s[i] <= '9')) ans = "No";
    }
    cout << ans << endl;
    return 0;
}