#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    string b;
    cin >> a >> b;

    if(a >= b.size()){
        cout << b;
    }else{
        cout << b.substr(0,a) << "...";
    }
    return 0;
}