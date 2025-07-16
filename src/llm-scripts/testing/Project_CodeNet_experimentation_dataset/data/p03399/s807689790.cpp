#include <iostream>
using namespace std;

int main (void){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a <= b) {
        if(c < d){
            cout << a + c << endl;
        }else{
            cout << a + d << endl;
        }
    }else{
        if(c < d){
            cout << b + c << endl; 
        }else{
            cout << b + d << endl;
        }
    }

    return 0;
}
