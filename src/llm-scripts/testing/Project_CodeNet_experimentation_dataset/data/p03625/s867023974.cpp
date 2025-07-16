#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        m[a]++;
    }
    vector<int> use;
    for(auto p:m){
        if(p.second>=4){
            use.push_back(p.first);
            use.push_back(p.first);
        }
        else if(p.second >=2){
            use.push_back(p.first);
        }
    }
    sort(use.begin(), use.end());
    reverse(use.begin(), use.end());
    if(use.size()<=1){
        cout << 0 << endl;
        return 0;
    }
    cout << (ll)use.at(0)*use.at(1) << endl;
}