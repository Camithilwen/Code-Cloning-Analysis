#include <stdio.h>
#include <math.h>

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    int n; scanf("%d", &n);
    int x[8], y[8];
    double ans = 0.0;
    
    for (int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            ans += dist(x[i], y[i], x[j], y[j]) * 2 / n;
        }
    }

    printf("%.10lf\n", ans);
}