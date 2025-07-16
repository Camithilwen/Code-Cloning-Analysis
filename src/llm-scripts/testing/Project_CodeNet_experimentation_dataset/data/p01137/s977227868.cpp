#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;
typedef long long ll;

int main()
{
    int n;
    while(cin >> n && n) {
        int ans = INF;
        rep(i,101) {
            if(i*i*i > n) break;

            rep(j,1001) {
                if(i*i*i + j*j > n) break;
                ans = min(ans,i+j+(n - i*i*i - j*j));
            }
        }

        cout << ans << endl;
    }

    return 0;
}