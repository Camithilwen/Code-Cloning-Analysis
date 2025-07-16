#include <bits//stdc++.h>
using namespace std;
int main(void){
    
    while(1){
        long long i,j,a,b,c,k,l;
        cin>>a>>b;
        if(a==0&&b==0)
        break;
        long long island[a][a];
        for(i=0;i<a;i++){
            for(j=0;j<a;j++){
                if(i==j)
                    island[i][j]=0;
                    
                else
                    island[i][j]=LLONG_MAX/2;
                    
            }
        }
        int frag=0;
        for(l=0;l<b;l++){
            cin>>c;
            if(c){
                long long d,e,f;
                cin>>d>>e>>f;
                if(island[d-1][e-1]>f){
                    island[d-1][e-1]=f;
                    island[e-1][d-1]=f;
                    frag=1;
                }
            }
            else{
                
                if(frag){
                    frag=0;
                    for(k=0;k<a;k++){
                        for(j=0;j<a;j++){
                            for(i=0;i<a;i++)
                            island[i][j]=min(island[i][j],island[i][k]+island[k][j]);
                        }
                    }
                }
                long long d,e;
                cin>>d>>e;
                long long ans=island[d-1][e-1];
                if(ans<LLONG_MAX/2)
                cout<<ans<<endl;
                else
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;
    
}

