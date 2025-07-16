#include <iostream>
#include <string>
using namespace std;

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int level(int j, int o, int i) {
    int c = min(j, o, i);
    if (c == o) return c;
    else return 0;
}

int main() {
    string s; cin >> s;
    int j_count = 0, o_count = 0, i_count = 0;
    int count = 0;
    char state = 'f';  // f: first, J: J, O: O, I: I
    for (string::iterator p = s.begin(); p != s.end(); p++) {
        switch (state) {
            case 'f':
                if (*p == 'J') {
                    j_count = 1;
                    state = 'J';
                }
                break;
            case 'J':
                if (*p == 'J') {
                    j_count++;
                } else if (*p == 'O') {
                    o_count = 1;
                    state = 'O';
                } else {
                    j_count = 0;
                    o_count = 0;
                    i_count = 0;
                    state = 'f';
                }
                break;
            case 'O':
                if (*p == 'O') {
                    o_count++;
                } else if(*p == 'I') {
                    i_count = 1;
                    state = 'I';
                    if (p == s.end()-1) {
                        int _count = level(j_count, o_count, i_count);
                        if (count < _count) {
                            count = _count;
                        }
                    }
                } else {
                    if (*p == 'J') {
                        j_count = 1;
                        o_count = 0;
                        i_count = 0;
                        state = 'J';
                    } else {
                        j_count = 0;
                        o_count = 0;
                        i_count = 0;
                        state = 'f';
                    }
                }
                break;
            case 'I':
                if (*p == 'I') {
                    i_count++;
                    if (p == s.end()-1) {
                        int _count = level(j_count, o_count, i_count);
                        if (count < _count) {
                            count = _count;
                        }
                    }
                } 
                if (*p != 'I') {
                    int _count = level(j_count, o_count, i_count);
                    if (count < _count) {
                        count = _count;
                    }
                    if (*p == 'J') {
                        state = 'J';
                        j_count = 1;
                        o_count = 0;
                        i_count = 0;
                    } else {
                        state = 'f';
                        j_count = 0;
                        o_count = 0;
                        i_count = 0;
                    }
                }
                break;
        }
    }
    cout << count << endl;
    return 0;
}