#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    std:ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<int> vi;
    int L;
    for(int i=0;i<2*N;++i){
        cin>>L;
        vi.push_back(L);
    }

    sort(vi.begin(), vi.end());
    int sum=0;
    for(int i=0;i<vi.size();i+=2){
        sum+=vi[i];
    }
    cout<<sum;
    return 0;
}

