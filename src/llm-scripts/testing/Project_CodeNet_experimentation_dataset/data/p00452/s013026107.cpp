#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
    int N;
    long long M;

    cin >> N >> M;

    while(N!=0 && M!=0) {
        vector<long long> p;

        long long ans=0;

        for(int i=0; i<N; ++i) {
            long long temp;
            cin >> temp;
            p.push_back(temp);
            ans=MAX(ans,temp);
        }

        sort(p.begin(),p.end());

        for(int i=0; i<N; ++i) {
            for(int j=i; j<N; ++j) {
                if(p[i]+p[j]>M) break;
                p.push_back(p[i]+p[j]);
                ans=MAX(ans,p[i]+p[j]);
            }
        }

        sort(p.begin(),p.end());

        for(int i=0; i<(int)p.size(); ++i) {
            auto itr=upper_bound(p.begin(),p.end(),M-p[i]);
            if(itr==p.begin()) break;
            else --itr;
            ans=MAX(ans,p[i]+*itr);
        }

        cout << ans << endl;
        cin >> N >> M;
        p.clear();
    }
    return 0;
}