#include <iostream>
using namespace std;

int main( void )
{
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    if ( ( ( e - a ) <= ( 4 * k ) ) && ( ( d + e - a - b ) <= ( 3 * k ) ) &&
         ( ( d + e - a - b ) <= ( 2 * k ) ) && ( ( e - a ) <= ( k ) ) )
    {
        cout << "Yay!" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }

    return 0;
}
