#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 1000;
    for(int i = 0; i+2 < s.length(); i++){
        int num = (s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
        if(abs(753-num) < ans) ans = abs(753-num);
    }
    cout << ans << endl;
    return 0;
}