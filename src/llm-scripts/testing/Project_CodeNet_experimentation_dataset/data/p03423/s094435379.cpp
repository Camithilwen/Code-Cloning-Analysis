#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        if(n<3)cout << 0 << endl;
        else if(n<6)cout << 1 << endl;
        else {
           cout << n/3 << endl; 
        }
    }
    return 0;
}
