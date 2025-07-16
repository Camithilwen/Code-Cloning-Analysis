#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    const int w = 52;
    const int h = 100;
    char field[h][w];
    int a, b;
    cin >> a >> b;
    a--, b--;

    rep(i, h / 2)
    {
        rep(j, w)
            field[i][j] = '.';
    }
    rep(i, h / 2)
    {
        rep(j, w)
            field[i + h / 2][j] = '#';
    }

    rep(i, 20)
    {
        if (b == 0)
            break;
        else
        {
            rep(j, 25)
            {
                if (b == 0)
                    break;
                else
                {
                    field[2 * i + 1][2 * j + 1] = '#';
                    b--;
                }
            }
        }
    }

    rep(i, 20)
    {
        if (a == 0)
            break;
        else
        {
            rep(j, 25)
            {
                if (a == 0)
                    break;
                else
                {
                    field[2 * i + h / 2 + 1][2 * j + 1] = '.';
                    a--;
                }
            }
        }
    }

    cout << h << " " << w << endl;
    rep(i, h)
    {
        rep(j, w)
                cout
            << field[i][j];
        cout << endl;
    }

    return 0;
}