#include <iostream>
using namespace std;

int main(void)
{
    int x; cin >> x;
    int ans = 0;
    ans += 1000 * (x / 500);
    x = x % 500;
    ans += 5 * (x / 5);
    cout << ans << endl;
}