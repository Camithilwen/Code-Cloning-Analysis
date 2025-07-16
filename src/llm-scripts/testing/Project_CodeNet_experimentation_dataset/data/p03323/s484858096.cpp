#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
    int l, i=0, a[10];
    while(2 > i){
        cin >> a[i];
        i++;
    }
    if (a[0] > 8 || a[1] > 8) {
        cout << ":(" << "\n";
    } else {
        cout << "Yay!" << "\n";
    }
}