// 解き直し.
// https://img.atcoder.jp/soundhound2018-summer-qual/editorial.pdf
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    double n, m, d;
    scanf("%lf %lf %lf", &n, &m, &d);
    
    // 2. 出力.
    if(d == 0) printf("%.10lf", (m - 1.0) * 1.0 / n);
    else       printf("%.10lf", (m - 1.0) * 2.0 * (n - d) / n / n);
    return 0;
    
}