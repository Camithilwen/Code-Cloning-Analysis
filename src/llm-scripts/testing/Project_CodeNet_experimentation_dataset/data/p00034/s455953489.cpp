#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
    int l[10];
    int a,b;
    while(~scanf("%d,", &l[0])) {
        double sum = 0;
        for(int i=1; i<10; i++) scanf("%d,", &l[i]);
        scanf("%d,%d",&a,&b);
        for(int i=0; i<10; i++) sum += (double)l[i];

        double c=0, d=0;
        int i;
        for(i=0; i<10; i++) {
            c += l[i];
            d += (double)l[i]/a * b;
            if(c + d >= sum) break;
        }

        printf("%d\n", i+1);
    }

    return 0;
}