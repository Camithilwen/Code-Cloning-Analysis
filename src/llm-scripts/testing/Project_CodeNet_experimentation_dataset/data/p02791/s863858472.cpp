#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, input;
    cin >> n;

    int mn = n, cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> input;
        if(input < mn)
            mn = input;
        if(mn >= input)
            cnt++;
    }

    cout << cnt;


    return 0;
}
