#include <iostream>
#include <vector>
using namespace std;
int n,m,q,v[2002][2002],e[2][2002][2002];
string s[2002];
int main(void){
    cin>>n>>m>>q;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            v[i][j]=e[0][i][j]=e[1][i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1][j-1]=='1'){
                v[i][j]++;
                if(j>1){
                    if(s[i-1][j-2]=='1'){
                        e[0][i][j]++;
                    }
                }
                if(i>1){
                    if(s[i-2][j-1]=='1'){
                        e[1][i][j]++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v[i][j]+=v[i][j-1];
            e[0][i][j]+=e[0][i][j-1];
            e[1][i][j]+=e[1][i][j-1];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            v[i][j]+=v[i-1][j];
            e[0][i][j]+=e[0][i-1][j];
            e[1][i][j]+=e[1][i-1][j];
        }
    }

    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int t=0;
        t+=v[c][d]-v[c][b-1]-v[a-1][d]+v[a-1][b-1];
        t-=e[0][c][d]-e[0][c][b]-e[0][a-1][d]+e[0][a-1][b];
        t-=e[1][c][d]-e[1][c][b-1]-e[1][a][d]+e[1][a][b-1];
        cout<<t<<endl;
    }
}
