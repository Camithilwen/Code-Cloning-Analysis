#include <cstdio>
#include <stdlib.h>

int main()
{
    int s[600];
    int t[6];
    int c = 0;
    char h[4] = {'N', 'S', 'W', 'E'};
    int n;
    bool a = false;
    scanf("%d", &n);
    for (int i = 0; i < 6 * n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            int k = rand() % 4;
            if (h[k] == 'N')
            {
                t[4] = s[0 + i * 6];
                t[0] = s[1 + i * 6];
                t[1] = s[5 + i * 6];
                t[5] = s[4 + i * 6];
                t[2] = s[2 + i * 6];
                t[3] = s[3 + i * 6];
            }
            if (h[k] == 'S')
            {
                t[0] = s[4 + i * 6];
                t[1] = s[0 + i * 6];
                t[5] = s[1 + i * 6];
                t[4] = s[5 + i * 6];
                t[2] = s[2 + i * 6];
                t[3] = s[3 + i * 6];
            }
            if (h[k] == 'W')
            {
                t[0] = s[2 + i * 6];
                t[2] = s[5 + i * 6];
                t[5] = s[3 + i * 6];
                t[3] = s[0 + i * 6];
                t[1] = s[1 + i * 6];
                t[4] = s[4 + i * 6];
            }
            if (h[k] == 'E')
            {
                t[2] = s[0 + i * 6];
                t[5] = s[2 + i * 6];
                t[3] = s[5 + i * 6];
                t[0] = s[3 + i * 6];
                t[1] = s[1 + i * 6];
                t[4] = s[4 + i * 6];
            }
            for (int j = 0; j < 6; j++)
            {
                s[j + i * 6] = t[j];
            }
            for (int j = i + 1; j < n; j++)
            {
                if (s[0 + i * 6] == s[0 + j * 6] && s[1 + i * 6] == s[1 + j * 6] && s[2 + i * 6] == s[2 + j * 6] && s[3 + i * 6] == s[3 + j * 6] && s[4 + i * 6] == s[4 + j * 6] && s[5 + i * 6] == s[5 + j * 6])
                {
                    a = true;
                    break;
                }
            }
            if (c == 1000)
            {
                break;
            }
            c += 1;
        }
    }

    if (a == false)
    {
        printf("Yes\n");
    }
    if (a == true)
    {
        printf("No\n");
    }
}
