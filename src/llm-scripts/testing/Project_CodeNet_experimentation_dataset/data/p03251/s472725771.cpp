#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> x1(n+1);
    vector<int> y1(m+1);
    for(int i = 0; i < n; i++) cin >> x1[i];
    for(int i = 0; i < m; i++) cin >> y1[i];

    string ans = "War";
    for(int z = x+1; z <= y; z++){
        bool isok = true;
        for(int i = 0; i < n; i++){
            if(x1[i] >= z) isok = false;
        }
        
        for(int i = 0; i < m; i++){
            if(y1[i] < z) isok = false;
        }

        if(isok) ans = "No War";
    }

    cout << ans << endl;
    return 0;
}