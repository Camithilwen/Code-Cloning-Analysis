#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    int n;
    cin >> n;
    vector<long int>f(n);
    int i;
    string s;
    s = "YES";
    for (i = 0; i < n; i++)
    {
        cin >> f.at(i);
    }
    sort(f.begin(), f.end());
    for (i = 0; i < n - 1; i++)
    {
        if (f.at(i) == f.at(i + 1))
        {
            s = "NO";
            break;
        }
    }
    cout << s << endl;
    
}