#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBERS(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

ll Earliest(ll N, ll K, vector<ll> Xs)
{
    vector<ll> ret(N-K+1);
    for(ll i=0;i<N-K+1;i++)
    {
        if(Xs[i+K-1]<=0)
        {
            ret[i] = abs(Xs[i]);
        }
        else if(Xs[i]<=0)
        {
            ret[i] = abs(Xs[i]-Xs[i+K-1]) + min(abs(Xs[i]),Xs[i+K-1]);
        }
        else
        {
            ret[i] = Xs[i+K-1];
        }
    }
    return *min_element(ALL(ret));
}

int main()
{
    ll N,K;
    cin >> N >> K;

    vector<ll> Xs(N);
    ALLIN1_NUMBERS(Xs);

    OUT0(Earliest(N,K,Xs));

    return 0;
}