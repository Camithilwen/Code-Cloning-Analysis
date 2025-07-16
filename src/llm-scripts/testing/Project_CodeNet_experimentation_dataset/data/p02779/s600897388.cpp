#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);


    int n;

    cin >> n;

    set <int> s;

    for(int i=0; i<n; i++)
    {
        int temp;

        cin >> temp;

        s.insert(temp);
    }

    if(s.size() == n)
    {
        cout << "YES";
    }

    else
    {
        cout << "NO";
    }
}







