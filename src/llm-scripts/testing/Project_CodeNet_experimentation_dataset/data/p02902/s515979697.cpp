#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

#define SEARCHED_NODE 2
#define START_NODE 1
#define ROUTE_NODE 1
#define INIT_NODE 0

int _flag[1000];
vector<vector<int>> *_edge;
vector<int> *_invloop;
vector<int> *_nextinvloop;
int _startnode;
bool search(int c, int p)
{
    if( _flag[c] == SEARCHED_NODE) return false;
    _flag[c] = ROUTE_NODE;
    vecrep(itr, (*_edge)[c])
    {
        if( _flag[*itr] == ROUTE_NODE ) 
        {
            _flag[*itr] = START_NODE;
            _invloop->push_back(c);
            return true;
        }
    }

    vecrep(itr, (*_edge)[c])
    {
        if( search(*itr, c) ) 
        {
            if(  _flag[*itr] != ROUTE_NODE )
            {
                _flag[*itr] = INIT_NODE;
            } 
            else
            {
                _invloop->push_back(c);
            }
            return true;
        }
    }
    _flag[c] = SEARCHED_NODE;

    return false;
}

pair<int, int> checkloop()
{
    int ls = _invloop->size();
    rep(i, ls)
    {
        int next = i - 1;
        if( next < 0 ) next = ls + next;
        int node = (*_invloop)[i];
        int nextnode = (*_invloop)[next];
        vecrep(itr, (*_edge)[node])
        {
            if(  _flag[*itr] == ROUTE_NODE && *itr != nextnode ) return make_pair(node, *itr);
        }
    }
    return make_pair(-1, -1);
}

void resetflag(int n)
{
    rep(j, n) _flag[j] = 0;
    vecrep(itr, (*_invloop)) _flag[*itr] = ROUTE_NODE;
}

void newloop(int s, int e)
{
    int loopindex = 0;
    while((*_invloop)[loopindex] != s ) loopindex++;
    _nextinvloop->clear();

    while((*_invloop)[loopindex] != e )
    {
        _nextinvloop->push_back((*_invloop)[loopindex]);
        loopindex = (loopindex + 1) % _invloop->size();
    }
    _nextinvloop->push_back(e);
    swap(_invloop, _nextinvloop);
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> edge(n);
    _edge = &edge;
#if 1    
    rep(i, m)
    {
        int a, b; cin >> a >> b; a--; b--;
        edge[a].push_back(b);
    }
#else
    rep(i, m)
    {
        int a, b; cin >> a >> b; a--; b--;
        edge[0].push_back(i + 1);
    }
#endif
    vector<int> invloop; _invloop = &invloop;
    vector<int> nextinvloop; _nextinvloop = &nextinvloop;
    rep(j, n) _flag[j] = INIT_NODE;
    rep(i, n)
    {
        if( search(i, -1) )
        {
            while( true )
            {
                resetflag(n);
                pair<int, int> ret = checkloop();
                if( ret.first < 0 ) break;
                newloop(ret.first, ret.second);
            }
            sort(_invloop->begin(), _invloop->end());
            cout << _invloop->size() << endl;
            vecrep(itr, *_invloop) cout << *itr + 1 << endl;
            return 0;
        } 
    }
    cout << -1 << endl;
    return 0;    
}