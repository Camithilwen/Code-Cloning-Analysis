#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<char> ss = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                         'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main  ()
{
    int n;
    while (cin >> n, n) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++) {
            int t = (str[i] - (('a' <= str[i] && str[i] <= 'z') ? 'a' : ('A' - 26)) - v[i % n] + 52) % 52;
            cout << ss[t];
        }
        cout << endl;
    }

    return 0;
}