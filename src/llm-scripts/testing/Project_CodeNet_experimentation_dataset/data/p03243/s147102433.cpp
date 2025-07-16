#include <iostream>
using namespace std;
int main(void){
    int n,i;
    cin >> n;
    for(i=n;i<n+111;i++){
        if(i%111==0) break;
    }
    cout << i;
}