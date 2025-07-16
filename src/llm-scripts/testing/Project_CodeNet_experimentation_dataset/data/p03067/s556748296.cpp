#include <iostream>
using namespace std;
int main(void){
    int a, b, c; cin >> a >> b >> c;
    if ((a <= c && c <= b) || (b <= c && c <= a)) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}