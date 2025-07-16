#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

set<pair<int,pair<int,int> > > query; //time, q, x. q=0:delete or 1: insert or 2:query
Int N,Q;

int main(void) {
    cin>>N>>Q;

    for(int i = 0;i < N;i++) {
        int s,t,x;
        cin>>s>>t>>x;
        query.insert({s-x, make_pair(1, x)});
        query.insert({t-x, make_pair(0, x)});
    }
    for(int i = 0;i < Q;i++) {
        int d;
        cin>>d;
        query.insert({d, make_pair(2, i)});
    }

    vector<int> D(Q);
    multiset<int> se;
    for(auto it: query) {
        int time = it.first;
        int q = it.second.first;
        int x = it.second.second;
        if(q == 0) {
            se.erase(se.find(x));
        } else if(q == 1) {
            se.insert(x);
        } else {
            if(se.empty()) {
                D[x] = -1;
            } else {
                D[x] = *se.begin();
            }
        }
    }

    for(int i = 0;i < Q;i++) {
        cout<<D[i]<<endl;
    }

    return 0;
}
