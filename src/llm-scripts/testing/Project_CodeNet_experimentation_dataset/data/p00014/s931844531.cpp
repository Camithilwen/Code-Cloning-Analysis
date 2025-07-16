#include <iostream>
using namespace std;

int main() {
    long d;
    while(cin >> d) {
        long count = 0;
        for(int i=0; i<600; i+=d) {
            count += d*i*i;
        }
        cout << count << endl;
    }
    return 0;
}