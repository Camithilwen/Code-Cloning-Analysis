#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string convert(string str) {
    int idx = 0;
    for (;;) {
        idx = str.find("Hoshino", idx);
        if (idx == string::npos) break;
        str.replace(idx, 7, "Hoshina");
        idx += 7;
    }
    return str;
}

int main() {
    int n;
    string str;
    getline(cin, str);
    n = atoi(str.c_str());
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        cout << convert(str) << endl;
    }
    return 0;
}