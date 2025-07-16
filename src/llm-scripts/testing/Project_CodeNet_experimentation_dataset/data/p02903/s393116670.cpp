#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll H, W, A, B;
    cin >> H >> W >>A >> B;

    vector<string> ansS(H);
    vector<ll> countH(W, 0);
    REP(i, H)
    {
        REP(j, W)
        {
            if (i < B)
            {
                if (j < A)
                {
                    ansS[i].push_back('0');
                }
                else
                {
                    ansS[i].push_back('1');
                }
            }
            else
            {
                if (j < A)
                {
                    ansS[i].push_back('1');
                }
                else
                {
                    ansS[i].push_back('0');
                }
            }
        }
    }

    REP(i, H)
    {
        cout << ansS[i] << endl;
    } 
}
