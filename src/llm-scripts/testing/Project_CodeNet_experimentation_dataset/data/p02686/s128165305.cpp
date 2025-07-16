#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* _minn;
int* _total;

bool compare(int i1, int i2)
{
    if( _minn[i1] != _minn[i2] ) return _minn[i1] > _minn[i2];
    return _total[i1] > _total[i2];
}

bool comparen(int i1, int i2)
{
    return _minn[i1] < _minn[i2];
}

bool check(int &count, vector<int> &l)
{
    sort(l.begin(), l.end(), compare);
    queue<int> q;
    int current = 0;
    for( auto itr = l.begin(); itr != l.end(); itr++ ) 
    {
        if( current + _minn[*itr] < 0 )
        {
            return false;
        }
        current += _total[*itr];
    }
    count = current;
    return true;
}

bool check(vector<int> &pindex, vector<int> &nindex, int lminmin, int rminmin)
{
    int c1 = 0;
    int c2 = 0;
    if( !check(c1, pindex) ) return false;
    if( !check(c2, nindex) ) return false;
    if( c1 != c2 ) return false;
    if( lminmin + c1 < 0 ) return false;
    if( rminmin + c2 < 0 ) return false;
    return true;
}

int main()
{
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    int* minn = mallocint(n);
    int* total = mallocint(n);
    _minn = minn;
    _total = total;
    vector<int> pindex;
    vector<int> nindex;
    int lminmin = 0;
    int rminmin = 0;
    for( int i = 0; i < n; i++ )
    {
        getline(cin, s);
        int lcount = 0;
        int lmin = 0;
        int rcount = 0;
        int rmin = 0;
        for( int j = 0; j < s.length(); j++ )
        {
            if (s.at(j) == '(') lcount++;
            if (s.at(j) == ')') lcount--;
            if( lcount < lmin ) lmin = lcount;
        }

        for( int j = s.length() - 1; j >= 0; j-- )
        {
            if (s.at(j) == ')') rcount++;
            if (s.at(j) == '(') rcount--;
            if( rcount < rmin ) rmin = rcount;
        }
        
        if( lcount > 0 )
        {
            minn[i] = lmin;
            total[i] = lcount;

            pindex.push_back(i);
        }
        else if( rcount > 0 )
        {
            minn[i] = rmin;
            total[i] = rcount;
            nindex.push_back(i);                    
        }
        else
        {
            if( lmin < lminmin ) lminmin = lmin;
            if( rmin < rminmin ) rminmin = rmin;
        }
        
    }

    if(check(pindex, nindex, lminmin, rminmin))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }    
}
