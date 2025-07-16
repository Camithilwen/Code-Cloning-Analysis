#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define Opy ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

int main()
{
    //Opy;

/*-------------------------------------------------
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
-------------------------------------------------*/
    string A;

    cin>> A;

    if(A[0] == 'R' && A[1] == 'R' && A[2] == 'R') cout<< "3\n";
    
    else if((A[0] == 'R' && A[1] == 'R') || (A[1] == 'R' && A[2] == 'R'))
    {
        cout<< "2\n";
    }

    else if(A[0] == 'S' && A[1] == 'S' && A[2] == 'S') cout<< "0\n";

    else cout<< "1\n";

    return 0;
}
