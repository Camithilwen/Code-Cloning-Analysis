#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main (void){
    int r;
    cin >> r;
    if(2800 <= r){
        cout << "AGC" << endl;
    }else if(1200 <= r){
        cout << "ARC" << endl;
    }else{
        cout << "ABC" << endl;
    }

    return 0;
}
