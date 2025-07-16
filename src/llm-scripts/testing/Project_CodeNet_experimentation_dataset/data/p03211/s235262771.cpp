#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int mini = 10000;
    for (int i = 0; i < s.length()-2; i++) {
        int x = atoi(s.substr(i, 3).c_str());
        mini = min(abs(x - 753), mini);
    }

    cout << mini << endl;
}