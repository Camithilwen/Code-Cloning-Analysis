//g++  7.4.0

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    std::string s;
    cin >> s;

    if(s.length() <= k){
        cout << s << endl;
    }else{
        cout << s.substr(0, k) << "..." << endl;
    }
}