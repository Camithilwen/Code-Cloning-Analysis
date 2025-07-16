#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;
 
int N, Q;
int main() {
    while(cin >> N >> Q, N||Q){
        int num[101];
        for(int i=0; i<101; ++i) num[i]=0;
        for(int i=0; i<N; ++i){
            int M; cin >> M;
            for(int j=0; j<M; ++j){
                int a; cin >> a;
                num[a]++;
            }
        }
        bool ok=false;
        int maxV = 0;
        int ans=0;
        for(int i=0; i<101; ++i){
            if(num[i]>=Q){
                if(maxV<num[i]) {
                    ans = i;
                    maxV = num[i];
                }
                ok =true;
            }
        }
        if(!ok) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
