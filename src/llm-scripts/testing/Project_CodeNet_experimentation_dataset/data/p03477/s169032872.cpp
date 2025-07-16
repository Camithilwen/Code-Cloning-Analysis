#include <iostream>
using namespace std;
int main(void){
    // Your code here!]
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = a + b;
    int ans1 = c + d;
    if(ans > ans1){
        cout << "Left" << endl;
    }
    else if(ans == ans1){
        cout << "Balanced" << endl;
    }
    else {
        cout << "Right" << endl;
    }
}
