#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b, c, k, x, y, z;
    cin >> a >> b >> c >> k;
    if(a >= b && a >= c)
    {x = a; y = b; z = c;}
    if(b > a && b >= c)
    {x = b; y = c; z = a;}
    else if(c > a && c > b)
    {x = c; y = a; z = b;}
    while(k > 0)
    {
        k--;
        x = x * 2;
    }
    cout << y + z + x;
    return 0;
}