#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

class Dice
{
public:
    int label[6], tmp;

    void in()
    {
        rep(i, 6) scanf("%d", &label[i]);
    }

    void rollS()
    {
        tmp = label[0];
        label[0] = label[4];
        label[4] = label[5];
        label[5] = label[1];
        label[1] = tmp;
    }

    void rollN()
    {
        tmp = label[0];
        label[0] = label[1];
        label[1] = label[5];
        label[5] = label[4];
        label[4] = tmp;
    }

    void rollE()
    {
        tmp = label[0];
        label[0] = label[3];
        label[3] = label[5];
        label[5] = label[2];
        label[2] = tmp;
    }

    void rollW()
    {
        tmp = label[0];
        label[0] = label[2];
        label[2] = label[5];
        label[5] = label[3];
        label[3] = tmp;
    }

    void sideturn()
    {
        tmp = label[1];
        label[1] = label[2];
        label[2] = label[4];
        label[4] = label[3];
        label[3] = tmp;
    }
};

bool check2(Dice d1, Dice d2)
{
    bool c = true;
    FOR(i, 1, 5)
    {
        c = c && d1.label[i] == d2.label[i];
    }

    return c;
}

bool check1(Dice d1, Dice d2)
{
    bool b = false;

    if (d1.label[0] == d2.label[0] && d1.label[5] == d2.label[5])
    {
        rep(i, 4)
        {
            b = b || check2(d1, d2);
            d2.sideturn();
        }
    }
    return b;
}

bool isSame(Dice d1, Dice d2)
{
    bool a = false;

    a = a || check1(d1, d2);
    d2.rollN();
    a = a || check1(d1, d2);
    d2.rollE();
    a = a || check1(d1, d2);
    d2.rollE();
    a = a || check1(d1, d2);
    d2.rollE();
    a = a || check1(d1, d2);
    d2.rollN();
    a = a || check1(d1, d2);

    return a;
}

int main()
{
    int n;
    bool ans = false;
    scanf("%d", &n);
    Dice dice[n];
    rep(i, n) dice[i].in();

    rep(i, n)
    {
        FOR(j, i + 1, n)
        {
            ans = ans || isSame(dice[i], dice[j]);
        }
    }

    if (ans)
        printf("No\n");
    else
        printf("Yes\n");
}
