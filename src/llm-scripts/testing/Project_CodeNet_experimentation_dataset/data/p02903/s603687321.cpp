#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int h, w, a, b;
    cin>>h>>w>>a>>b;
    vector<vector<int> > v(h, vector<int>(w));
    if(w/2>=a && h/2>=b){
        vector<int> s1(w);
        vector<int> s2(w);
        rep(i, a){
            s1[i] = 1;
        }
        for(int i = a;i<=w-1;i++){
            s2[i] = 1;
        }
        rep(i, b){
            v[i] = s1;
        }
        for(int i = b;i<=h-1;i++){
            v[i] = s2;
        }
        rep(i, h){
            rep(j, w) cout<<v[i][j];
            cout<<endl;
        }
    }
    else cout<<"No"<<endl;
    return 0;
}