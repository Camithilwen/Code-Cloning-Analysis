#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <map>
#include <stack>
#define ll long long
using namespace std;

int main()
{
    double n;
    cin >> n;
    double ave=0;
    vector<double> a(n);
    for (ll i =0; i < n;i++){
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    //cout << ave << endl;
    ll ans = n - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if(abs(a[ans]-ave)>=abs(a[i]-ave)){
            ans = i;
        }
    }
    cout << ans << endl;
}
