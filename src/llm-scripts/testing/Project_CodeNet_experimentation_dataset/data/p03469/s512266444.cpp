#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    
    cout << "2018/";
    
    for (int i=0; i<s.size(); i++) {
        if (i > 4) cout << s.at(i);
    }
    cout << endl;
}

