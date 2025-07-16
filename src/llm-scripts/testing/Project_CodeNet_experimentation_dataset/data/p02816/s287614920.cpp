#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;

int s[maxn], t[maxn];
int a[maxn], b[maxn];
int fail[maxn];

int n, m;
void getfail()
{
    memset(fail, 0, sizeof(fail));
    int len = n;
    int j = 0, k = fail[0] = -1;
    while (j < len)
    {
        while (k != -1 && t[j] != t[k])
            k = fail[k];
        fail[++j] = ++k;
    }
}

int kmp()
{
    int i = 0, j = 0;
    int ret = 0;
    while (i < n * 2)
    {
        while (j != -1 && s[i] != t[j])
            j = fail[j];
        i++, j++;
        if (j == m)
        {
            //printf("debug: i: %d j: %d\n", i, j);
            if (i < 2 * n)
                printf("%d %d\n", i - j, a[(i - j)] ^ b[0]);
            ret++, j = fail[j];
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    m = n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i < n; i++)
        s[i] = a[i] ^ a[(i + 1) % n], t[i] = b[i] ^ b[(i + 1) % n];
    for (int i = n; i < 2 * n; i++)
        s[i] = s[i - n];
    /*     for (int i = 0; i < 2 * n; i++)
        cout << s[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << t[i] << " ";
    cout << endl; */
    getfail();
    kmp();
}