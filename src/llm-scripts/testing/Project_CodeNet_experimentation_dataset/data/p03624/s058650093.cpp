#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;
int main() {
    string x; 
    cin >> x;
    for (int j = 97; j <= 122; j++) {
        bool a = 0;
        for (int i = 0; i < x.size(); i++) {
            if (char(j) == x[i]) {
                a = 1;
                continue;
            }
        }
        if (a == 0) {
            cout << char(j);
            return 0;
        }
    }
    cout << "None";
    return 0;
}