#include <iostream>
#include <string.h>
#include <sstream>
#include <ctype.h>
using namespace std;

string com[3] = {"the", "this", "that"};

string incAlpha (string str, int k) {
    for (int i = 0; i < str.size(); i++) {
        if(isalpha(str[i])) str[i] = ((str[i] + k - 'a') % 26) + 'a'; 
    }
    return str;
}

bool strsrch(string str1, string str2) {
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == str2[0]) {
            bool flag = true;
            if (i + str2.size() > str1.size()) flag = false;
            for (int j = 0; j < str2.size() && flag; j++) {
                if (str1[i + j] != str2[j]) flag = false;
            }
            if (flag) return true;
        }
    }

    return false;
}

bool check (string str) {
    for (int i = 0; i < 3; i++) {
        if (strsrch(str, com[i])) return true;
    }
    return false;
}

int main ()
{
    string str;
    while (getline(cin, str)) {
        for (int i = 0; i <= 26; i++) {
            if (check((incAlpha(str, i)))) {
                cout << (incAlpha(str, i)) << endl;
                break;
            }
        }
    }

    return 0;
}