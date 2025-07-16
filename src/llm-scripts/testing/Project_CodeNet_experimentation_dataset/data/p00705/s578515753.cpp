#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int n, q, m, d, dt, days[101];
    while(cin >> n >> q && n && q) {
        memset(days, 0, sizeof(days));
        for(int i = 0; i < n; i++) {
            cin >> d;
            for(int j = 0; j < d; j++) {
                cin >> dt;
                days[dt]++;
            }
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++)
            if(days[i] >= q && days[i] > days[ans])
                ans = i;
        
        cout << ans << endl;
    }
}