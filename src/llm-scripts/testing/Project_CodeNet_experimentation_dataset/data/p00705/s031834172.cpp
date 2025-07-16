#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int n, q, m, d;
        int mxd=0;
        set<int> s[50];
        int date=0;
        cin >> n >> q;
        if(!(n||q)) break;
        --q;
        for(int i=0;i<n;++i){
            cin >> m;
            for(int j=0;j<m;++j){
                cin >> d;
                s[i].insert(d);
                mxd = max(mxd, d);
            }
        }
        for(int i=1;i<=mxd;++i){
            int cnt=0;
            for(int j=0;j<n;++j){
                if(s[j].find(i)!=s[j].end()) ++cnt;
            }
            if(q<cnt){
                q = cnt;
                date = i;
            }
        }
        cout << date << endl;
    }
}