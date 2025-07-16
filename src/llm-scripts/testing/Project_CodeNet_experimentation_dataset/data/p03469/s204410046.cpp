#include<iostream>
#include<string>

using namespace std;

int main() {
    string date;
    cin >> date;
    
    date.replace(0, 4, "2018");
    cout << date;
}