#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    string S;
    cin >> N;

    ll D = N % 10;
    N = (N - D) / 10;
    ll C = N % 10;
    N = (N - C) / 10;
    ll B = N % 10;
    N = (N - B) / 10;
    ll A = N % 10;

    ll tmp = 0;

    bool flag = flase;

    REP(i,2){
        REP(j,2){
            REP(k,2){
                if(i==0){
                    tmp = A + B;
                }
                else{
                    tmp = A - B;
                }
                if (j == 0)
                {
                    tmp += C;
                }
                else
                {
                    tmp -= C;
                }
                if (k == 0)
                {
                    tmp += D;
                }
                else
                {
                    tmp -= D;
                }
                if(tmp==7){
                    cout << A;
                    if (i == 0)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << "-";
                    }
                    cout << B;
                    if (j == 0)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << "-";
                    }
                    cout << C;
                    if (k == 0)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << "-";
                    }
                    cout << D;
                    cout << "=7" << endl;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

}
