
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    std::vector<long long> trips;
    int ans=0;
    cin>>n;
    trips.resize(n);
    for(auto &x:trips)
        cin>>x;
    n = trips.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(trips[i]!=trips[j] && trips[i]!=trips[k] && trips[j]!=trips[k])
                    if(trips[i]+trips[j]>trips[k] && trips[i]+trips[k]>trips[j] && trips[j]+trips[k]>trips[i])
                        ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
