#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,maxl=0,minr=1000000;
    cin >> n >> m;
    vector<int> l(m),r(m);
    for(int i=0;i<m;i++){
        cin >> l.at(i) >> r.at(i);
        if(l.at(i)>maxl)maxl=l.at(i);
        if(r.at(i)<minr)minr=r.at(i);
    }
    if(minr-maxl+1>0)cout << minr-maxl+1 << endl;
    else cout << 0 << endl;
    return 0;
}