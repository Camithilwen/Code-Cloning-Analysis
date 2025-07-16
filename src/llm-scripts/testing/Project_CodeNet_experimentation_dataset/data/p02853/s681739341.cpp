#include "iostream"
using namespace std;
int main(){
    int x,y,price=0;
    cin>>x>>y;
    for (int i=1; i<=3; i++) {
        if (x==i) {
            price+=(4-i)*100000;
        }
        if (y==i) {
            price+=(4-i)*100000;
        }
    }
    if (x==1&&y==1) {
        cout<<"1000000"<<endl;
    } else {
        cout<<price<<endl;
    }
}
