#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> v[2];
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        v[i%2].push_back(tmp);
    }

    if(n==2)
    {
        if(v[0][0]==v[1][0])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        
    }

    int tab0[100010];
    FILL0(tab0); 
    rep(i, v[0].size())
    {
        tab0[v[0][i]]++;
    }

    vector<P> freq0;

    rep(i, 100001)
    {
        if(tab0[i]!=0)
        {
            freq0.push_back(P(tab0[i], i));
        }
    }

    int tab1[100010];
    FILL0(tab1); 
    rep(i, v[1].size())
    {
        tab1[v[1][i]]++;
    }


    vector<P> freq1;

    rep(i, 100001)
    {
        if(tab1[i]!=0)
        {
            freq1.push_back(P(tab1[i], i));
        }
    }

    sort(freq0.begin(), freq0.end());
    reverse(freq0.begin(), freq0.end());

    sort(freq1.begin(), freq1.end());
    reverse(freq1.begin(), freq1.end());
    

    if(freq0[0].second==freq1[0].second)
    {
        if(freq0[0].first-freq0[1].first>freq1[0].first-freq1[1].first)
        {
            cout << n-(freq0[0].first+freq1[1].first) << endl; 
        }
        else
        {
            cout << n-(freq1[0].first+freq0[1].first) << endl;     
        }
        
    }
    else
    {
        cout << n-(freq0[0].first+freq1[0].first) << endl;
    }




    return 0;
}

