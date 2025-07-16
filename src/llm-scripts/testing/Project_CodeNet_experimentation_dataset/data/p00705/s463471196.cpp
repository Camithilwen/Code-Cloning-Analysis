#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    while(cin >> n && n != 0){
        cin >> q;
        map<int,int> d;
        for(int i = 0;i < n; i++){
            int m; cin >> m;
            for(int j = 0; j < m; j++){
                int t; cin >> t;
                if(d.find(t) != d.end()){
                    d[t]++;
                }
                else{
                    d[t] = 1;
                }
            }
        }
        int ans = 0, num = 0;
        for(map<int,int>::iterator it = d.begin(); it != d.end(); it++){
            if(it->second > num){
                ans = it->first;
                num = it->second;
            }
        }
        if(num < q){
            cout << 0 << endl;
        }
        else cout << ans << endl;
    }

	return 0;
}


