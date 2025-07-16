#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    int n; cin >> n;
    long long sum = 0;
    int counter = 0;
    vector<long> a(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> a[i];
    for(int i = 1; i < n + 1; i++){
        if(a[i] < 0){
           counter += 1; 
        }
        a[i] = abs(a[i]);
    }

    sort(a.begin() + 1, a.end());
    for(int i = 1; i < n + 1; i++) sum += a[i];

    if(counter % 2 == 0 ){
      cout << sum << endl;
    }else{
      cout << sum - 2 * a[1] << endl;
    }
    
    //output
}