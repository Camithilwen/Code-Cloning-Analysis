#include<bits/stdc++.h>
using namespace std;

#define int long long

int N;
int odd[100010], even[100010];

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if(i & 1) even[a]++;
        else odd[a]++;
    }

    int odd_index = -1, odd_max = -1;
    for(int i = 0; i < 100010; i++)
    {
        if(odd_max < odd[i])
        {
            odd_max = odd[i];
            odd_index = i;
        }
    }

    int even_index = -1, even_max = -1;
    for(int i = 0; i < 100010; i++)
    {
        if(even_max < even[i])
        {
            even_max = even[i];
            even_index = i;
        }
    }
    
    if(even_index != odd_index)
    {
        cout << N - even_max - odd_max << endl;
        return 0;
    }

    int odd_max2 = -1;
    for(int i = 0; i < 100010; i++)
    {
        if(odd_max2 < odd[i] && i != odd_index)
        {
            odd_max2 = odd[i];
        }
    }

    int even_max2 = -1;
    for(int i = 0; i < 100010; i++)
    {
        if(even_max2 < even[i] && i != even_index)
        {
            even_max2 = even[i];
        }
    }

    cout << min(N - even_max - odd_max2, N - even_max2 - odd_max) << endl;

    return 0;
}
