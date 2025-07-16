#include <iostream>
using namespace std;
int main()
{
    bool cr = false, cg = false, cb = false;
    int n;
    long long ans = 0;
    string s;
    cin >> n >> s;
    int r[n + 1], g[n + 1], b[n + 1];
    r[0] = 0;
    g[0] = 0;
    b[0] = 0;
    for(int i = 0; i < n; i++)
    {
        r[i + 1] = r[i];
        g[i + 1] = g[i];
        b[i + 1] = b[i];
        if(s[i] == 'R')
        {
            r[i + 1]++;
        }
        else if(s[i] == 'G')
        {
            g[i + 1]++;
        }
        else
        {
            b[i + 1]++;
        }
    }
    for(int i  = 0; i < n - 2; i++)
    {
        if(s[i] == 'R')
        {
            cr = true;
        }
        else if(s[i] == 'G')
        {
            cg = true;
        }
        else
        {
            cb = true;
        }
        for(int j = i + 1; j < n - 1; j++)
        {
            if(s[i] != s[j])
            {
                if(s[j] == 'R')
                {
                    cr = true;
                }
                else if(s[j] == 'G')
                {
                    cg = true;
                }
                else
                {
                    cb = true;
                }
                if(!cr)
                {
                    ans += r[n] - r[j];
                    if(j + j - i < n && s[j + j - i] == 'R')
                    {
                        ans--;
                    }
                }
                else if(!cg)
                {
                    ans += g[n] - g[j];
                    if(j + j - i < n && s[j + j - i] == 'G')
                    {
                        ans--;
                    }
                }
                else
                {
                    ans += b[n] - b[j];
                    if(j + j - i < n && s[j + j -i] == 'B')
                    {
                        ans--;
                    }
                }
                if(s[j] == 'R')
                {
                    cr = false;
                }
                else if(s[j] == 'G')
                {
                    cg = false;
                }
                else
                {
                    cb = false;
                }
            }
        }
        if(s[i] == 'R')
        {
            cr = false;
        }
        else if(s[i] == 'G')
        {
            cg = false;
        }
        else
        {
            cb = false;
        }
    }
    cout << ans << endl;
    return 0;
}
