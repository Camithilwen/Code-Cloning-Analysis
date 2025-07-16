#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N; string S; vi l,r;
void input()
{
    cin>>N>>S;
}

void solve()
{
    int count=0;
    for(int i=0;i<N;++i) {
        if(S[i]=='W') ++count;
        l.emplace_back(count);
    }
    count=0;
    for(int i=0;i<N;++i) {
        if(S[N-1-i]=='E') ++count;
        r.emplace_back(count);
    }
    int MIN=100000000;
    for(int i=0;i<N;++i) {
        int tmp=0;
        if(i>0) tmp+=l[i-1];
        if(i<N-1) tmp+=r[N-2-i];
        MIN=min(MIN,tmp);
    }
    cout<<MIN<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}