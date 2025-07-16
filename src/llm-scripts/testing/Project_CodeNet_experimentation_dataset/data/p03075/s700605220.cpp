#include <iostream>
using namespace std;
int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(e - a > f){
        cout << ":(" << endl;
        return 0;
    }
    cout << "Yay!" << endl;
}