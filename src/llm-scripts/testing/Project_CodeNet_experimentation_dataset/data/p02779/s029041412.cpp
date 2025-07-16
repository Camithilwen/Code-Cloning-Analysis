#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int main()
{
    Tayeb;
    int N,count=0;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    for(int i=1; i<N; i++)
    {
        if(arr[i]==arr[i-1])
        count++;
    }
    if(count==0)
    cout << "YES" << "\n";
    else
    cout << "NO" << "\n";


    return 0;

}
