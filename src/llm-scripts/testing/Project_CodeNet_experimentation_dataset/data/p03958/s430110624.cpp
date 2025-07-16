#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int k,t;
    cin >> k >> t;
    multiset<int> s;
    rep(i,t){
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    int st = 0;
    rep(i,k){
        if(s.size()==0){
            cout << st << endl;
            return 0;
        }
 
 
        int temp = *(--s.end());
        --temp;
        //cout << " " << temp << endl;
        s.erase(--s.end());
        //cout << "  " << s.size() << endl;
        if(st>0&&i>0) s.insert(st);
        st = temp;
    }

    cout << 0 << endl;
}