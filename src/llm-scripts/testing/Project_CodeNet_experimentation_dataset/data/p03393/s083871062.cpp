#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    set<char> st;
    for(int i=0; i<str.size(); i++) {
        st.insert(str[i]);
    }
    
    if(st.size()<26) {
        cout << str;
        for(int i=0; i<26; i++) {
            if(st.find((char)('a'+i))==st.end()) {
                cout << (char)('a'+i) << endl;
                break;
            }
        }
    } else {
        set<char> vec;
        vec.insert(str[25]);
        int i;
        for(i=25; i>=1; i--) {
            if(str[i-1]<str[i]) {
                break;
            }
            vec.insert(str[i-1]);
        }
        if(vec.size()==26) {
            cout << -1 << endl;
        } else if(vec.upper_bound(str[i-1])!=vec.end()) {
            for(int j=0; j<i-1; j++) {
                cout << str[j];
            }
            cout << (*vec.upper_bound(str[i-1])) << endl;
        }
    }


    return 0;
    
}