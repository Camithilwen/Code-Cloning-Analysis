#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int og = 0;
    for(int i = 0; i < n; ++i){
        v[i] = k + i;
        og += v[i];
    }   
    int index = 0;
    int maxi = INT_MAX;
    for(int i = 0; i < n; ++i){
        int dif = og - v[i];
        int dist = abs(og - dif);
        if(maxi > dist){
            maxi = dist;
            index = i;
        }
    }
    cout << og - v[index] << '\n';
    return 0;  
}