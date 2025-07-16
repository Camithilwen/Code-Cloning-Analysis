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

class Dishes
{
    public:
    ll point_takahashi;
    ll point_aoki;
    ll sum;
    ll number;
};

void ALLIN1_DISHES(ll N, vector<Dishes>& dishes)
{
    for(ll i=0;i<N;i++)
    {
        dishes[i].number = i;
        cin >> dishes[i].point_takahashi >> dishes[i].point_aoki;
        dishes[i].sum = dishes[i].point_takahashi + dishes[i].point_aoki;
    }
}

bool Sort_TA(vector<Dishes>& dishesTA)
{
    sort
    (ALL(dishesTA),
    [](Dishes& a, Dishes& b)
    {
        return (a.sum == b.sum) ? (a.point_takahashi > b.point_takahashi) : (a.sum > b.sum);
    });
}

void Sort_AT(vector<Dishes>& dishes)
{
    sort
    (ALL(dishes),
    [](Dishes& a, Dishes& b)
    {
        return (a.sum == b.sum) ? (a.point_aoki > b.point_aoki) : (a.sum > b.sum);
    });
}

ll Ans(ll N, vector<Dishes> dishes_TA, vector<Dishes> dishes_AT)
{
    vector<bool> eaten(N,false);
    ll takahashi_point = 0;
    ll aoki_point = 0;

    ll itr_TA = 0;
    ll itr_AT = 0;

    for(ll i=0;i<N;i++)
    {
        if(i%2==0)
        {
            for(ll& j=itr_TA;j<N;j++)
            {
                if(!eaten[dishes_TA[j].number])
                {
                    eaten[dishes_TA[j].number] = true;
                    takahashi_point += dishes_TA[j].point_takahashi;
                    j++;
                    break;
                }
            }
        }
        else
        {
            for(ll& j=itr_AT;j<N;j++)
            {
                if(!eaten[dishes_AT[j].number])
                {
                    eaten[dishes_AT[j].number] = true;
                    aoki_point += dishes_AT[j].point_aoki;
                    j++;
                    break;
                }
            }
        }
    }
    return takahashi_point - aoki_point;
}

int main()
{
    ll N;
    cin >> N;

    vector<Dishes> dishes(N);
    ALLIN1_DISHES(N,dishes);

    vector<Dishes> dishes_TA = dishes;
    Sort_TA(dishes_TA);

    vector<Dishes> dishes_AT = dishes;
    Sort_AT(dishes_AT);

    OUT0(Ans(N,dishes_TA,dishes_AT));

    return 0;
}