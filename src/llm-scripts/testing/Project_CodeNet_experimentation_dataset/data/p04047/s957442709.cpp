#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[220];
int n;
int main(){
    cin >> n;
    for(int i=0;i<2*n;i++){
        cin >> a[i];
    }
    sort(a,a+n*2);
    int len=0;
    for(int i=0;i<n;i++){
        len+=a[2*i];
    }
    cout << len;
}