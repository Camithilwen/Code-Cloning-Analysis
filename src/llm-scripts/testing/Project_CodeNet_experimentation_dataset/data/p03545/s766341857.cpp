#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
typedef pair<int,int> P;
const int INF=1e9;
int main(){
    string s;
    cin>>s;
    rep(i,1<<3){
        int sum=0;
        sum+=s[0]-'0';
        for(int j=1;j<4;j++){
            if(i>>(j-1)&1) sum+=s[j]-'0';
            else sum-=s[j]-'0';
        }
        if(sum==7){
            cout<<s[0];
            rep(j,3){
                if(i>>j&1) cout<<'+';
                else cout<<'-';
                cout<<s[j+1];
            }
            break;
        }
    }
    cout<<"=7";
}