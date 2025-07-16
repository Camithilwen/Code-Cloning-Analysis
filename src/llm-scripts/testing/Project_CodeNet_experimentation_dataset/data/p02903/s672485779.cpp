#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <stdlib.h>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
using namespace std;

bool test = true;
#define log(x) if(test) cout << "[ " << #x << " = " << x << " ]\n";
#define log2(x, y) if(test) cout << "[ " << #x << " = " << x << ", " << #y << " = " << y << " ]\n"; 
#define logv(x) if(test) {cout << #x << " : { "; for(auto i : x) cout << i << " "; cout << "}\n";}; 

#define MX (ll)(1e14)

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    int ans[n+1][m+1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            ans[i][j] = 0;
    }
    
    for(int i=1; i<=b; i++) {
        for(int j=1; j<=a; j++) {
            ans[i][j] = 1;
        }
    }

    for(int i=b+1; i<=n; i++) {
        for(int j=a+1; j<=m; j++) {
            ans[i][j] = 1;
        }
    }

     for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            cout << ans[i][j];
        cout << "\n";
    }
    

    
}