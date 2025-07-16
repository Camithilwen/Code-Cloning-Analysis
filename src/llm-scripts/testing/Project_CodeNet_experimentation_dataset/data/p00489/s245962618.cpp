#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int A,B,C,D;
    vector<pair<int,int> > P;
    vector<int> R;

    cin >> N;

    P.push_back({1000000000,-1});
    R.resize(N+1);

    for(int i=1; i<=N; ++i) P.push_back({0,i});

    for(int i=0; i<N*(N-1)/2; ++i) {
        cin >> A >> B >> C >> D;
        if(C==D) {
            ++P[A].first;
            ++P[B].first;
        } else if(C>D) {
            P[A].first+=3;
        } else {
            P[B].first+=3;
        }
    }

    sort(P.rbegin(),P.rend());

    int rnk=1;

    R[P[1].second]=1;

    for(int i=2; i<=N; ++i) {
        if(P[i-1].first!=P[i].first) rnk=i;
        R[P[i].second]=rnk;
    }

    for(int i=1; i<=N; ++i) {
        cout << R[i] << endl;
    }

    return 0;
}