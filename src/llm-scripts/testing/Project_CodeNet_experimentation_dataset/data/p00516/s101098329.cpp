#include <iostream>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)

int main() {
    int n,m;
    cin>>n>>m;
    int A[1000], B[1000];
    rep(i,n) cin>>A[i];
    int c[1000]={};
    rep(i,m) cin>>B[i];
    rep(j,m)rep(i,n){
        if(B[j]>=A[i]){
            c[i]++;
            break;
        }
    }
    int mx=0, num=0;
    rep(i,n){
        if(mx<c[i]){
            num=i; mx=c[i];
        }
    }
    cout<<num+1<<endl;
}