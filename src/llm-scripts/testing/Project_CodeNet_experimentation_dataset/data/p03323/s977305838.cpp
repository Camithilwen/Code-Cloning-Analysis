#include <iostream>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    
    bool can;
    
    if  (A > 8 || B > 8) can = false;
    else can = true;
    
    if (can) cout << "Yay!" << endl;
    else cout << ":(" << endl;
}