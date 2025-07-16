#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Thousand "Hello World"
    int R, G;
    cin >> R >> G;
    if (R + ((G - R) * 2) / 2 == G){
        cout <<R + ((G - R) * 2) << endl;
    }
    else{
        cout << (R - G) * -1 << endl;
    }
}
