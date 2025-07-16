#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    int x,y;
    cin >> x >> y;
    int ans = 0;
    switch (x)
    {
    case 1:
        ans += 300000;
        switch (y)
        {
        case 1:
            ans += 700000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
        }
        break;
    case 2:
        ans += 200000;
        switch (y)
        {
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
        }
        break;
    case 3:
        ans += 100000;
        switch (y)
        {
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
        }
        break;
    default:
        switch (y)
        {
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}