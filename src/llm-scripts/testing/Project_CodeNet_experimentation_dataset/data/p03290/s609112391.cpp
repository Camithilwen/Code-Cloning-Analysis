#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    int D;
    long long G;
    int p[10];
    long long c[10];
    long long sum[10];
    long long ans = 10000000;
    
    cin >> D >> G;
    for (int i = 0;i < D;i++){
        cin >> p[i] >> c[i];
        sum[i] = 100*(i+1)*p[i] + c[i];
    }
    
    for (int i = 0;i < (1<<D);i++){
        long long res = 0;
        long long pre = 0;
        for (int j = 0;j < D;j++){
            if ((i>>j)%2){
                res += sum[j];
                pre += p[j];
            }
        }
        if (res < G){
            for (int j = D-1;j >= 0;j--){
                if ((i>>j)%2==0){
                    for (int k = 0;k < p[j]-1;k++){
                        res += 100*(j+1);
                        pre++;
                        if (res >= G){
                            goto EXIT;
                        }
                    }
                }
            }
        }
        EXIT:
        if(res >= G){
            ans = min(ans,pre);
        }
    }
    cout << ans << endl;
}
