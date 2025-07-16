#include <iostream>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    if(x==1&&y==1){
        cout << 1000000 << endl;
    }else if(x==1&&y==2) {
        cout << 500000 << endl;
    }else if(x==1&&y==3) {
        cout << 400000 << endl;
    }else if(x==2&&y==1) {
        cout << 500000 << endl;
    }else if(x==2&&y==1) {
        cout << 500000 << endl;
    } else if(x==2&&y==2) {
        cout << 400000 << endl;
    } else if(x==2&&y==3) {
        cout << 300000 << endl;
    } else if(x==3&&y==1) {
        cout << 400000 << endl;
    } else if(x==3&&y==2) {
        cout << 300000 << endl;
    } else if(x==3&&y==3) {
        cout << 200000 << endl;
    } else if(x<=3) {
        cout << (4-x)*100000 << endl;
    } else if(y<=3){
        cout << (4-y)*100000 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}