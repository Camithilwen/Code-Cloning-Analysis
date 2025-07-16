#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

#define MMAX (1000*1000)
pair<int, int> _next[MMAX];
int _in[MMAX];
int _day[MMAX];

int getindex(int i, int j, int n)
{
    return min(i, j) * n + max(i, j);
}

bool searchsub(int day, int next, queue<int> &q)
{
    if( next < 0 ) return true;
    _in[next]--;
    _day[next] = max(_day[next], day);
    if( _in[next] == 0 ) q.push(next);
    return false;
}


int main()
{
    int n; cin >> n;
    vector<int> first(n);
    rep(i, n * n) { _next[i].first = -1;  _next[i].second = -1; _in[i] = 0; _day[i] = -1;}

    rep(i, n)
    {
        int pre = -1;    
        rep(j, n - 1)
        {
            int a; cin >> a; a--;
            int index = getindex(i, a, n);
            if(j == 0)
            {
                 first[i] = index;
            }
            else
            {
                if( _next[pre].first < 0 )
                {
                     _next[pre].first = index;
                }
                else
                {
                     _next[pre].second = index;
                }
            }
            _in[index]++;
            pre = index;
        }
    }

    int ans = 0;
    queue<int> q;
    rep(i, n)
    {
        searchsub(1, first[i], q);
    }

    while(!q.empty())
    {
        int index = q.front();
        q.pop();
        ans = max(ans, _day[index]);
        searchsub(_day[index] + 1, _next[index].first, q);
        searchsub(_day[index] + 1, _next[index].second, q);
    }
    bool flag = false;
    rep(i, n * n)
        if( _in[i] > 0 ) flag = true;

    if( flag )
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;    
}