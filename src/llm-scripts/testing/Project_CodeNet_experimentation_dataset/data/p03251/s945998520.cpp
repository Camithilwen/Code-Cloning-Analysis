#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int minx=200,miny=200,maxx=-200,maxy=-200;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        maxx=max(maxx,a);
        minx=min(minx,a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        maxy=max(maxy,a);
        miny=min(miny,a);
    }
    if(maxx<miny&&maxx<y&&miny>x)cout<<"No War"<<endl;
    else cout<<"War"<<endl;

    return 0;
}