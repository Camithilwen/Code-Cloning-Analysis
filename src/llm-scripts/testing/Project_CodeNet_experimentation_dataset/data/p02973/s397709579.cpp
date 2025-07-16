#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    multiset<int> ms;
    for(auto a : A)
    {
        if(ms.empty() || *ms.begin() >= a) ms.insert(a);
        else
        {
            auto itr = ms.lower_bound(a);
            if(itr == ms.end() || *itr >= a) itr--;
            ms.erase(itr);
            ms.insert(a);
        }
    }
    cout << ms.size() << endl;

    return 0;
}
