#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, init, n) for(int i = init; i < (n); i++)

using namespace std;
using ll = long long int;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using edge = struct
{
    int to, cost;
};

const int MOD = 1e9 + 7;
const int iINF = 1e9;
const long long int llINF = 1e18;
const double PI = acos(-1.0);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int a, b, c;
    
    while(cin >> a >> b >> c, a, b, c)
    {
        vector<int> sta(a + b + c + 1, 2);

        int N;
        cin >> N;

        vector<tuple<int, int, int, int>> vec;

        rep(num, N)
        {
            int i, j, k, r;

            cin >> i >> j >> k >> r;

            vec.push_back(make_tuple(r, i, j, k));
        }

        sort(vec.begin(), vec.end(), greater<tuple<int, int, int, int>>());

        rep(num, N)
        {
            int i, j, k, r;
            tie(r, i, j, k) = vec[num];

            if(r == 1)
            {
                sta[i] = 1;
                sta[j] = 1;
                sta[k] = 1;
            }
            else if(r == 0)
            {
                int cnt = 0;

                 for(int pro : {i, j, k})
                {
                    if(sta[pro] == 1) cnt++;
                }

                if(cnt != 2) continue;

                for(int pro : {i, j, k})
                {
                    if(sta[pro] == 1) continue;

                    sta[pro] = 0;
                }
            }   
        }

        rep(i, a + b + c) cout << sta[i + 1] << endl;
    }
    return 0;
}
