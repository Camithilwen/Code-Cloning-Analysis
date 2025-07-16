#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

//Zeller's conguence

int main()
{
    int h, y, m, d;
    h = 20;
    y = 4;
    while (true)
    {
        cin >> m >> d;
        if (m == 0 && d == 0)
            break;
        if (m == 1 || m == 2)
        {
            m += 12;
            y--;
        }
        int r = 5 * h + h / 4;
        int w = {d + ((13 * (m + 1)) / 5) +
                 y + y / 4 + r + 5};

        int ans = w % 7 + 1;
        switch (ans)
        {
        case 7:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        }
    }
    return 0;
}