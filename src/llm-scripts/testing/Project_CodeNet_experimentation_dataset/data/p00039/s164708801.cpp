#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
    map<char,int> a = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    string str;
    while(getline(cin, str)) {
        int b = 0, c = a[str[0]], d = a[str[0]]; 
        for(int i = 1; i < str.length(); ++i) {
            int e = a[str[i]];
            if (e == d) {
                c += e;
            }
            else if (d < e) {
                b  -=  (c);
                c = e;
            }
            else if (e < d) {
                b += (c);
                c = e;
            }
            d = e;
        }
        b += c;
        cout << b << endl;;
    }
    return 0;
}

