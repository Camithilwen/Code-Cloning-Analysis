#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-8;
int n;
double x[102], y[102];
vector<double> v;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    for (int i = 1; i <= n; i ++) {
        v.clear();
        for (int j = 1; j <= n; j ++) if (i != j) {
            double a1 = atan2(y[j]-y[i], x[j]-x[i]);
            v.push_back(a1);            
        }
        
        sort(v.begin(), v.end());
        v.push_back(v[0] + 2*PI);
        

        int gg = 0; double gap = 0;
        for (int j = 0; j < (int)v.size() - 1; j ++) {
            //printf("%.3f\n", v[j]);
            if (v[j+1] - v[j] + EPS > PI) {
                gg ++; gap = v[j+1] - v[j];
            }
        }
        if (gg >= 2 || gap < PI) {
            printf("%.7f\n", 0.0);
            continue;
        } 
        //printf("%.6f\n", gap);
    
        printf("%.7f\n", (gap-PI) / 2 / PI);




    }
}