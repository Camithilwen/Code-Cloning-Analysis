#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1<<30;

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<int> A(H), B(H);
    for(int i=0; i<H; i++)
    {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    map<int, int> path;
    multiset<int> dist;
    for(int i=0; i<W; i++)
    {
        path[i] = i;
        dist.insert(0);
    }

    for(int i=0; i<H; i++)
    {
        int idx = -1;
        for(auto itr = path.lower_bound(A[i]); itr != path.end() && itr->first <= B[i] + 1; itr = path.erase(itr))
        {
            chmax(idx, itr->second);
            auto ditr = dist.find(itr->first - itr->second);
            dist.erase(ditr);
        }
        if(idx != -1 && B[i] + 1 < W)
        {
            path[B[i] + 1] = idx;
            dist.insert(B[i] + 1 - idx);
        }
        if(dist.size() == 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << *dist.begin() + i + 1 << '\n';
        }
    }

    return 0;
}
