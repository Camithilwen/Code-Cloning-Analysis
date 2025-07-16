#include <iostream>
#include <string>
using namespace std;

#define KEY_NUM 100

char process_key(char c, int key) {
    
    int num=0;
    //cout << "[" << c << "," << key << "," << num << "]";
    if ('a' <= c && c <= 'z') {
        num = 25 - (int)('z' - c);
    }
    if ('A' <= c && c <= 'Z') {
        num = 51 - (int)('Z' - c);
    }
    num = (num - key + 104) % 52;
    if ( 0 <= num && num <= 25) {
        c = 'a' + num;
    }
    if (26 <= num && num <= 51) {
        c = 'A' + (num - 26);
    }
    //cout << "[" << c << "," << key << "," << num << "]";
    return c;
}

int main(void) {
    string s;
    int n;
    int keys[KEY_NUM];
    while (cin >> n, n) {
        for (int i=0; i<n; i++) {
            cin >> keys[i];
        }
        cin >> s;
        //cout << n << endl;
        for (int i=0; i<s.size(); i++) {
            //cout << process_key(s[i], keys[i % n]) << "_";
            cout << process_key(s[i], keys[i % n]);
        }
        //cout << s << endl;
        cout << endl;
    }
}