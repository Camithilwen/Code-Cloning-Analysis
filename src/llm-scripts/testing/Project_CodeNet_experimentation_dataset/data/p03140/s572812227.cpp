#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
    rep(i,n){
        if(a[i]==b[i]&&a[i]==c[i])continue;
        if(a[i]==b[i]||a[i]==c[i]||b[i]==c[i])ans++;
        else ans+=2;
    }
    cout<<ans<<endl;
}