#include <iostream>
using namespace std;
long long d, t, s;
int main()
{
    cin >> d >> t >> s;
    if(t * s >= d)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
