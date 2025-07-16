#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;
const int INF = pow(2, 30) - 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;
    cin >> N >> S;

    vector<int> G;
    vector<int> R;
    vector<int> B;

    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == 'R')
        {
            R.push_back(i + 1);
        }
        else if (S.at(i) == 'G')
        {
            G.push_back(i + 1);
        }
        else if (S.at(i) == 'B')
        {
            B.push_back(i + 1);
        }
    }

    int tmp1, tmp2, tmp3;
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 1; i + 2 * j < N; j++)
        {
            if(i+2*j<N){
                if(S.at(i)=='R'){
                    tmp1 = 1;
                }
                else if(S.at(i)=='G'){
                    tmp1 = 2;
                }
                else if(S.at(i)=='B'){
                    tmp1 = 4;
                }
                if (S.at(i+j) == 'R')
                {
                    tmp2 = 1;
                }
                else if (S.at(i+j) == 'G')
                {
                    tmp2 = 2;
                }
                else if (S.at(i+j) == 'B')
                {
                    tmp2 = 4;
                }
                if (S.at(i + 2*j) == 'R')
                {
                    tmp3 = 1;
                }
                else if (S.at(i + 2*j) == 'G')
                {
                    tmp3 = 2;
                }
                else if (S.at(i + 2*j) == 'B')
                {
                    tmp3 = 4;
                }
                if(tmp1+tmp2+tmp3==7){
                    ans++;
                }
            }
        }
    }

    cout << R.size()*G.size()*B.size()-ans << endl;
}
