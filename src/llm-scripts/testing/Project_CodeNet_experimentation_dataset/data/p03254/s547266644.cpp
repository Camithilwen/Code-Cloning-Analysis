#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N;
    cin >> N;
    lli x;
    cin >> x;
    lli a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a, a + N);
    lli sum[N + 1];
    fill(sum, sum + N + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    for (int i = 0; i <= N; i++)
    {
        if (sum[i] > x)
        {
            cout << i - 1 << endl;
            return 0;
        }
        else if (sum[i] == x)
        {
            cout << i << endl;
            return 0;
        }
        else if (i == N)
        {
            cout << N - 1 << endl;
            return 0;
        }
    }
    return 0;
}
