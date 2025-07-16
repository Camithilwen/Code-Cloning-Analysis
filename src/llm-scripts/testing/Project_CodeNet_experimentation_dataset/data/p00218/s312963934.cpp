#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while(cin >> n && n){

        for(int i = 0; i < n; ++i){
            int pm, pe, pj;
            cin >> pm >> pe >> pj;  // ??°????????±????????????

            char ans = 'C';
            int ave = (pm + pe + pj) / 3;

            if(ave >= 50 && (pm >= 80 || pj >= 80)) ans = 'B';
            if(ave >= 70) ans = 'B';
            if(ave >= 80) ans = 'A';
            if(pm + pe >= 180) ans = 'A';
            if(pm == 100 || pe == 100 || pj == 100) ans = 'A';

            cout << ans << endl;
        }
    }

   return 0;
}