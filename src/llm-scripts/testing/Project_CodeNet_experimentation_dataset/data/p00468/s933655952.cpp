#include<iostream>
#include<vector>

using namespace std;
const int inf=1e8;

int main(){

    while(1){
        int n, m;
        cin>> n>> m;
        if(n==0&&m==0) break;
        int a[m], b[m];
        for(int i=0; i<m; i++){
            cin>> a[i]>> b[i];
            a[i]--; b[i]--;
        }

        int mtrx[n][n];
        fill(mtrx[0], mtrx[n], inf);
        for(int i=0; i<m; i++){
            mtrx[a[i]][b[i]]=mtrx[b[i]][a[i]]=1;
        }


        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    mtrx[i][j]=min(mtrx[i][j], mtrx[i][k]+mtrx[k][j]);

        int ans=0;
        for(int i=1; i<n; i++){
            if(mtrx[0][i]==2||mtrx[0][i]==1) ans++;
        }

        cout<< ans<< endl;

    }

    return 0;
}