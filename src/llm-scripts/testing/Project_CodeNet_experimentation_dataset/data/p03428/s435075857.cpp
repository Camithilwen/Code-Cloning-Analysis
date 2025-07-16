#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <ctime>
using namespace std;

int const MAX_N = 128;
int const MX_CNT = 2200000;

double x[MAX_N], y[MAX_N];
int cnt[MAX_N];

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>x[i]>>y[i];
    double R = 1e11;
    double ang_part = R / MX_CNT;
    int sum = 0;
    for (int i=0; i<MX_CNT; i++) {
        double xx = R*cos(ang_part*i);
        double yy = R*sin(ang_part*i);
        double mn_val = 1e150;
        int mn_ind = -1;
        for (int j=0; j<n; j++) {
            double val = (xx - x[j])*(xx - x[j]) + (yy - y[j])*(yy - y[j]);
            if (val < mn_val) {
                mn_val = val;
                mn_ind = j;
            }
        }
        cnt[mn_ind]++;
        sum++;
    }
    for (int i=0; i<n; i++) printf("%.6lf\n",cnt[i]/((double) sum));
   	return 0;
}