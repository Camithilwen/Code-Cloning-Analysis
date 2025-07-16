/**
*    author:  souzai32
*    created: 13.08.2020 13:17:00
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    sort(a.begin(),a.end());
    int c=0;
    for(int i=0; i<n; i++){
        if(a.at(i)<0){
            a.at(i)*=-1;
            c++;
        }
        else break;
    }

    sort(a.begin(),a.end());
    long long sum;
    if(c%2) sum=-a.at(0);
    else sum=a.at(0);
    for(int i=1; i<n; i++) sum+=a.at(i);

    cout << sum << endl;

    return 0;
}