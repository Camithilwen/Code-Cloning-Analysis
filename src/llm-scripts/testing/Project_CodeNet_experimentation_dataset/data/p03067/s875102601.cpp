#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c>min(a,b)&&c<max(a,b))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}