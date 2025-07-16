#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
bool isSheep[MAXN];
bool o[MAXN];
bool options[2] = {true, false};

bool isValid(int n)
{
    bool firstSheep = isSheep[0];
    for (int i = 1; i < n; i++)
    {
         if (isSheep[i] && o[i] || !isSheep[i] && !o[i])
         {
             isSheep[(i + 1) % n] = isSheep[i - 1];
         }
         else if (isSheep[i] && !o[i] || !isSheep[i] && o[i])
         {
             isSheep[(i + 1) % n] = !isSheep[i - 1];
         }
    }
    if (isSheep[0] != firstSheep)
        return false;
    if (firstSheep && o[0] || !firstSheep && !o[0])
    {
        return isSheep[n - 1] == isSheep[1];
    }
    else
    {
        return isSheep[n - 1] != isSheep[1];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        o[i] = c == 'o';
    }
    bool valid = false;
    for (bool s1 : options)
    {
        for (bool s2 : options)
        {
            isSheep[0] = s1;
            isSheep[1] = s2;
            if (isValid(n))
            {
                valid = true;
                break;
            }
        }
        if (valid)
            break;
    }
    if (valid)
    {
        stringstream ss;
        for (int i = 0; i < n; i++)
        {
            if (isSheep[i])
                ss << "S";
            else
                ss << "W";
        }
        cout << ss.str() << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
