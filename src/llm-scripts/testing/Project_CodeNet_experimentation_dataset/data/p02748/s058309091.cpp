#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,m;
    cin>>a>>b>>m;
    int ref[a],mic[b];
    for (int i=0;i<a;++i){
        cin>>ref[i];
    }
    for (int i=0;i<b;++i){
        cin>>mic[i];
    }
    int mini = INT_MAX;
    for(int i=0;i<m;++i){
        int x,y,c;
        cin>>x>>y>>c;
        mini = min(mini,ref[x-1]+mic[y-1]-c);
    }
    sort(ref,ref+a);
    sort(mic,mic+b);
    cout<<min(mini,ref[0]+mic[0]);
    
}