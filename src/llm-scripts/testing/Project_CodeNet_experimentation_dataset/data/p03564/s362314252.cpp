#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define d 1000000007
using namespace std;
int main()
{
    int t;
    t=1;
    while(t--)
    {
        int n,k;
        cin >> n;
        cin >> k;
        int result=1;
        while(n>0)
        {
            result=min(result*2,result+k);
            n--;
        }
        cout << result << endl;
    }
	return 0;
}