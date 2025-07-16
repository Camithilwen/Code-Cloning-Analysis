#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<n; ++i)
#define rep(i,n) reps(i,0,n)

int main()
{
    int m, a, b;
    
    while(cin >> m >> a >> b, m){
        vector<int> pt(m);
        for(int i=0; i<m; ++i){
            cin >> pt[i];
        }
        
        pair<int, int> ans{-1, -1};
        
        rep(p, 10000){
            vector<int> ok, ng;
            
            rep(i, m){
                if(pt[i] < p) ng.push_back(pt[i]);
                else ok.push_back(pt[i]);
            }
            
            int n = ok.size();
            if(a <= n && n <= b){
                int gap = *min_element(ok.begin(), ok.end()) - *max_element(ng.begin(), ng.end());
                ans = max(ans, {gap, ok.size()});
            }
        }
        
        cout << ans.second << endl;
    }
}