#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;

    if(*(--a.end()) == *(b.begin()) && *(--b.end()) == *(c.begin())){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}