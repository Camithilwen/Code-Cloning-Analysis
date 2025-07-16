#include <iostream>
#include <string>
using namespace std;
int main() {
    string S;
    cin >> S;
    cout << S.substr(0, S.size() - string("FESTIVAL").size()) << endl;
}
