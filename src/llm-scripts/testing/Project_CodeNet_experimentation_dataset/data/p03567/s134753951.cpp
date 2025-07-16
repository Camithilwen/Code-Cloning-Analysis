#include <iostream>
using namespace std;
int main() {
    string s;
    bool pri = 0;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == 'A'){
            if(i+1 != s.length() && s[i+1] == 'C'){
                cout << "Yes";
                pri = 1;
                break;
            }
        }
    }
    if(!pri){
        cout <<"No";
    }
    return 0;
}
