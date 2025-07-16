#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* inputint(int n)
{
    int *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}

#define _INF -2000000001

int main()
{
    int n;
    cin >> n;
    int *a = inputint(n);

    long long f0[2][3];
    long long f1[2][3];

    int wmax = (n % 2 == 0) ? 1 : 2;
    int index = 0;
    f0[0][0] = a[0];
    f0[0][1] = _INF;
    f0[0][2] = _INF;
    f1[0][0] = _INF;
    f1[0][1] = 0;
    f1[0][2] = _INF;
    index = 0;
    for( int i = 1; i < n; i++ )
    {
        int next = (index + 1) % 2;
        for( int w = 0; w <= wmax; w++ )
        {
            f0[next][w] = f1[index][w];
            if( f0[next][w] != _INF ) f0[next][w] += (long long)a[i];

            if( w > 0)
            {
                f1[next][w] = max(f1[index][w - 1], f0[index][w]);
            }
            else
            {
                f1[next][w] = f0[index][w];
            }
        }
        index = next;
    }

    long long ans = max(f0[index][wmax], f1[index][wmax - 1]);
    cout << ans;
    return 0;    
}