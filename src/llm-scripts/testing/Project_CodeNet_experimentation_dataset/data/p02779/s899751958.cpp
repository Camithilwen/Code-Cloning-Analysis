#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int arr[200001];
int main()
{
    fast_io;
    int n;
    cin >> n;
    set <int> s;
    for(int i =0 ; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    if(n == s.size())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
