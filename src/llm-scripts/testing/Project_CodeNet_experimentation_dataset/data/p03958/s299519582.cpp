#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for(int i=0; i<t; i++)cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    
    cout << max(a[0] - 1 - (k - a[0]), 0) << endl;
}
