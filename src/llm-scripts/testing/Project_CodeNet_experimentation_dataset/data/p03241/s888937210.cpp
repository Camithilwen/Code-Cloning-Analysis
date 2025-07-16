#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
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

vector<ll> Divs(ll N)
{
    map<ll,ll> ret_map;
    for(ll i=1;i*i<=N;i++)
    {
        if(N%i==0)
        {
            ret_map[i]++;
            ret_map[N/i]++;
        }
    }
    vector<ll> ret_vec;
    for(auto x : ret_map)
    {
        ret_vec.push_back(x.first);
    }
    return ret_vec;
}

ll Ans(ll N, ll M, vector<ll> div)
{
    sort(ALL(div),greater<ll>());
    for(auto x : div)
    {
        if(N * x <= M) return x;
    }
}

int main()
{
    ll N,M;
    cin >> N >> M;

    OUT0(Ans(N,M,Divs(M)));

    return 0;
}