#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
    {
        cin>>v[i];
    }

    int minsofar = INT_MAX;
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        minsofar = min(minsofar,v[i]);
        if(v[i] <= minsofar)
        {
            count++;
        }
    }
    
    cout<<count;
    
    return 0;
}