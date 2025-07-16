#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n,m,d;
    scanf("%ld %ld %ld", &n, &m, &d);
    long k;
    if(d == 0){
        k = n;
    }
    else{
        k = 2 * (n - d);
    }
    k = k * (m - 1);
    double dAns = double(k)/double(n * n);
    printf("%.10lf", dAns);
    return 0;
}
