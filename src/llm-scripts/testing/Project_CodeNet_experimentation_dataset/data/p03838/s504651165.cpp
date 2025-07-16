#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int mod = 1e9 + 7;

using namespace std;

int ans(int res)
{
        cout << res << "\n";
        exit(0);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int x, y;
        cin >> x >> y;
        if(x <= y){
                if(y <= 0) ans(y - x);
                if(x <= -y) ans(-y - x + 1);
                if(x < 0) ans(y + x + 1);
                ans(y - x);
        } else if(-x <= y){
                x = -x;
                if(y <= 0) ans(y - x + 1);
                if(x <= -y) ans(-y - x + 2);
                if(x < 0) ans(y + x + 2);
                ans(y - x + 1);
        } else{
                int res = 0;
                if(x < 0){
                        res = 1;
                        x = -x;
                }
                res += -y - x;
                res += 1;
                ans(res);
        }
}
