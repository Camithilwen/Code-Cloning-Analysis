
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    long x,y;cin>>x>>y;
    if(x<0&&y==0){
        cout<< -x;
    }
    if(x>=0&&y>=0){
        (y>x)?cout<<y-x:cout<<min(2+x-y,1+y+x);return 0;
    }
    else if(x<0&&y>0){
        (-x>y)?cout<<-x-y+1:cout<<1+x+y;return 0;
    }
    else if(x<0&&y<0){
        (y>x)?cout<<y-x:cout<<2+x-y;return 0;
    }
    else if(x>=0&&y<0){
        (-y>x)?cout<<-y-x+1:cout<<x+y+1;return 0;
    }
}
            
