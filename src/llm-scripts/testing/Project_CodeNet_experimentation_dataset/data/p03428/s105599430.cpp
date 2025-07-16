#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 
struct point{
    int x, y;
}w[110];
int n;
double P[210];
const double PI = acos(-1.0);
 
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i].x >> w[i].y;
    }
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            P[cnt++] = atan2(w[j].y - w[i].y, w[j].x - w[i].x);
        }
        sort(P, P+cnt);
        for(int j = 0; j < cnt; j++) P[j + cnt] = P[j]+2* PI;
        double res = 0.0;
        for(int j = 0; j < cnt; j++) {
            res = max(res, PI - P[j + cnt - 1] + P[j]);
        }
        printf("%.10f\n", res/(2*PI));
    }
    return 0;
}