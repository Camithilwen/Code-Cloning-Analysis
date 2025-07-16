#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = 0;
    while (n > 2)
    {
        x++;
        n = n - 3;
    }
    cout << x << endl;

    return 0;
}