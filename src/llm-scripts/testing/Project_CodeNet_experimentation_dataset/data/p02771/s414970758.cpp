#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a==b && b!=c){
        std::cout << "Yes" << std::endl;
    }
    else if (a==c && b!=c){
        std::cout << "Yes" << std::endl;
    }
    else if (b==c && b!=a){
        std::cout << "Yes" << std::endl;
    }
    else{std::cout << "No" << std::endl;}
    
}