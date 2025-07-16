#include <bits/stdc++.h>
using namespace std;
//vector<vector<int>> a(5, vector<int>(5, 0)) 5*5-0
int main(){
    long long int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    long long int step = 0;
    for(int i = 1; i < n; i++){
        if(a.at(i - 1) > a.at(i)){
            step += a.at(i - 1) - a.at(i);
            a.at(i) = a.at(i - 1);
        }
    }

    cout << step << endl;
}