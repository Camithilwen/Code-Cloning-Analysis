#include <bits/stdc++.h>
using namespace std;

int main(){
    int o,u,c;
    cin >> o >> u >> c;
    if(o<c&&c<u){
        cout << "Yes" << endl;
    }
    else if(o>c&&c>u){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}