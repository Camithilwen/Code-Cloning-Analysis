#include <bits/stdc++.h>

using namespace std;

long long n,i;

int main()
{
    cin >> n;
    for(i=111; i<=999; i+=111)
        if(i>=n) {
            cout<<i<<endl;
            break;
        }


    return 0;
}
