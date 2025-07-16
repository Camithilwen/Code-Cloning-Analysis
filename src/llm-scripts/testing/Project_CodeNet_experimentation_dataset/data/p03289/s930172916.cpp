#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int l = s.length();
    if(s[0]!='A'){
        cout << "WA\n";
        return 0;
    }
    int i, cnt = 0;
    for(i=1; i<l; i++){
        if(isupper(s[i])){
            if(i==1 || i==l-1 || s[i]!='C'){
                cout << "WA\n";
                return 0;
            }
            cnt++;
        }
    }
    if(cnt==1) cout << "AC\n";
    else cout << "WA\n";
    return 0;
}