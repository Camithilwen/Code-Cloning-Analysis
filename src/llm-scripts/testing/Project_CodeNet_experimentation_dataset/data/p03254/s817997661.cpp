#include <bits/stdc++.h>
using namespace std;

int main(){
    long int n,x;
    cin >> n >> x;
    vector<long int> a(n);
    long int sum=0;
    int i;

    for(i=0; i<n; i++){
        cin >> a.at(i);
        sum+=a.at(i);
    }
    sort(a.begin(),a.end());

    if(x>sum) cout << n-1 << endl;
    else if(x==sum) cout << n << endl;
    else{
        for(i=0; i<n; i++){
            sum-=a.at(n-1-i);
            if(x>=sum) break;
        }
        cout << n-1-i << endl;
    }
}