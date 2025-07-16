#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    int festival_len = 8;
    int name_len = s.size() - 8;
    for (int i=0;i<name_len;i++){
        cout << s[i];
    }
    cout << endl;

    return 0;
}