#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, bool> check;

    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        if (check[a]) {
            cout << "NO" << endl;
            return 0;
        }
        check[a] = true;
    }

    cout << "YES" << endl;
}

