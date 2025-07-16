#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    string a;
    string b;
    string c;
    cin >> a >> b >> c;
    char turn = a[0];
    a.erase(a.begin());
    if(a.empty()) {
        cout << 'A' << endl;
        return 0;
    }

    while(1){
        if(turn == 'a'){
            if(a.empty()) {
                cout << 'A' << endl;
                return 0;
            }
            turn = a[0];
            a.erase(a.begin());
        }

        if(turn == 'b'){
            if(b.empty()) {
                cout << 'B' << endl;
                return 0;
            }
            turn = b[0];
            b.erase(b.begin());
        }

        if(turn == 'c'){
            if(c.empty()) {
                cout << 'C' << endl;
                return 0;
            }
            turn = c[0];
            c.erase(c.begin());
        }   
    }    
    return 0;
}