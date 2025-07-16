#include <iostream>
using namespace std;

int main ()
{
    int p, q, r;
    cin >> p >> q >> r;
    cout << min(min(p + q, p + r), q + r);
}
