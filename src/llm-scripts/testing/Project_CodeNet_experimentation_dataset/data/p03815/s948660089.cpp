#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int x;
    cin>>x;
    if (x<=6) {
        cout<<1<<endl;
    } else {
        if (x%11==0) {
            cout<<2*(x/11)<<endl;
        } else if (x%11<=6) {
            cout<<2*(x/11)+1<<endl;
        } else {
            cout<<2*(x/11)+2<<endl;
        }
    }
}
