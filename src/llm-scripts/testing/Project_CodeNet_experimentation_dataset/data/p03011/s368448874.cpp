#include <bits/stdc++.h>
using namespace std ;

int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    int Ans = a[0]+a[1];
    cout << Ans << endl;

}