#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int w = 0, e = 0;
    for(int i=0; i<n; ++i){
        if(s[i]=='W'){w++;}
    }
    e = n-w;
    int nw = 0, ne = e;
    int mi = INT32_MAX; int c;
    for(int i=0; i<n; ++i){
        if(s[i]=='W' && i>0){nw++;}
        if(s[i]=='E' && i>0){ne--;}
        int pen = nw + ne; 
        if(mi>pen){mi = pen; c=i;}
    }
    int res = 0; //cout << "c:" << c << endl;
    for(int i=0; i<n; ++i){
        if(s[i]=='W' && i<c){res++;}
        if(s[i]=='E' && i>c){res++;}
    }
    cout << res << endl;
    return 0;
}