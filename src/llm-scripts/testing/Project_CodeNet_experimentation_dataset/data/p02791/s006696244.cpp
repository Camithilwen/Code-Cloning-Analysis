#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>> n;

    set<int>st;
    int input;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>> input;

        st.insert(input);

        if(input == *st.begin())
            ans++;
    }

    cout<< ans;
    
    return 0;
}
