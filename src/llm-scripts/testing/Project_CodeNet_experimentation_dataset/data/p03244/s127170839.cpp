#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

pair<int,int> func(map<int,int> m){
    int MAX = -1; int IDX;
    for(auto i=m.begin();i!=m.end();i++){
        if(MAX<i->second){IDX=i->first; MAX=i->second;}
    }
    pair<int, int> p = make_pair(IDX,MAX);
    return p;
}

int main() {
    int n; cin >> n;
    map<int,int> m1{};
    map<int ,int> m2{};
    for(int i=0;i<n;i++){
        int m; cin>>m;
        if(i%2==0)m1[m]++;
        else m2[m]++;
    }
    pair<int, int> M1 = func(m1);
    pair<int, int> M2 = func(m2);
    //cout << M1.first << M2.first << endl;
    if(M1.first == M2.first){
        m1[M1.first]=0; m2[M2.first]=0;
        pair<int, int> M3 = func(m1);
        pair<int, int> M4 = func(m2);
        cout << n-max(M1.second+M4.second, M2.second+M3.second) << endl;
    }
    else cout << n-M1.second- M2.second << endl;
}

