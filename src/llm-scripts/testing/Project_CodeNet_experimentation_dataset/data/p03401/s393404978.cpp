#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    vector<long long> a(n+1,0);
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        a[i] = b;
    }
    
    long long cumulativeSum = 0;
    
    for (int i = 1; i <= n; i++){
       
        cumulativeSum += abs(a[i]-a[i-1]);
        
    }
    cumulativeSum += abs(a[n]);
   
    
    // i番目を抜く
    for (int i = 1; i <= n; i++){
        long long temp = cumulativeSum;
        if (i == n){
            temp += abs(a[n-1]);
            temp -= abs(a[n-1] - a[n]);
            temp -= abs(a[n]);
            cout << temp << endl;
        }
        else{
            temp += abs(a[i-1] - a[i+1]);
            temp -= abs(a[i-1] - a[i]);
            temp -= abs(a[i] - a[i+1]);
            cout << temp << endl;
        }
    }
    
}