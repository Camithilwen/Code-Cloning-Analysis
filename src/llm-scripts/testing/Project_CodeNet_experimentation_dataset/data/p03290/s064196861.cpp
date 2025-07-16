#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, g;
    cin >> d >> g;
    vector <int> p(d);
    vector <int> c(d);
    
    for(int i = 0; i < d; ++i) cin >> p[i] >> c[i];

    int ans = 1e9;
    for(int mask = 0; mask < (1 << d); ++mask){
        int point = 0, num  = 0, rest_max = -1; 
        for(int i = 0; i < d; ++i){
            if(mask >> i & 1){
                point += 100 * (i + 1) * p[i] + c[i];
                num += p[i];
            }else{ 
                rest_max = i;
            }
        }
        if(point < g){
             int p1 = 100 * (rest_max + 1);
            int need = (g - point + p1 - 1)/p1;
            if(need >= p[rest_max])continue;
            num+= need;
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}