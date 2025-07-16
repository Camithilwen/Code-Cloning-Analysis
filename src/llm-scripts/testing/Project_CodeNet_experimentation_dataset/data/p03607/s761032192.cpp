
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i, m,c1=0,c2=0;
    cin >> n;
    set <int> winner;
    set <int>::iterator it1;
    multiset <int> loser;
    multiset <int>::iterator it2;
    for(i=0; i<n; i++)
    {
        cin >> m;
        winner.insert(m);
        loser.insert(m);
    }
    it1=winner.begin();
    it2=loser.begin();

    for(i=0; it1!=winner.end(); i++)
    {
        if(*it1==*it2)
        {
            c1 = c1+1;

            it2++;
        }
        else
        {
            it1++;
            c2 = c2 + (c1&1);

            c1 = 0;
        }
    }
    cout << c2 + (c1&1);

}
