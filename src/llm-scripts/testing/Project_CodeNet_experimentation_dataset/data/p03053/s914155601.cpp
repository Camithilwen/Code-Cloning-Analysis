#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    vector <vector <int>> m(h, vector <int> (w,3000));
    queue <vector <int>> q;
    int ans=0;

    string s,s2;
    vector <int> s3(3,0);
    rep(i,h){
        cin >> s;
        rep(j,w){
            s2=s[j];
            if(s2=="#"){
                s3[0]=i;
                s3[1]=j;
                q.push(s3);
                m[i][j]=0;
            }
        }
    }

    int x,y,z;
    vector <int> xyz,pu(3);
    while(q.size()!=0){
        xyz=q.front();
        q.pop();
        ans=max(ans,xyz[2]);
        m[xyz[0]][xyz[1]]=xyz[2];

        if(xyz[0]!=0){
            if(m[xyz[0]-1][xyz[1]]>xyz[2]+1){
                pu[0]=xyz[0]-1;
                pu[1]=xyz[1];
                pu[2]=xyz[2]+1;
                q.push(pu);
                m[xyz[0]-1][xyz[1]]=pu[2];
            }
        }
        if(xyz[0]!=h-1){
            if(m[xyz[0]+1][xyz[1]]>xyz[2]+1){
                pu[0]=xyz[0]+1;
                pu[1]=xyz[1];
                pu[2]=xyz[2]+1;
                q.push(pu);
                m[xyz[0]+1][xyz[1]]=pu[2];
            }
        }
        if(xyz[1]!=0){
            if(m[xyz[0]][xyz[1]-1]>xyz[2]+1){
                pu[0]=xyz[0];
                pu[1]=xyz[1]-1;
                pu[2]=xyz[2]+1;
                q.push(pu);
                m[xyz[0]][xyz[1]-1]=pu[2];
            }
        }
        if(xyz[1]!=w-1){
            if(m[xyz[0]][xyz[1]+1]>xyz[2]+1){
                pu[0]=xyz[0];
                pu[1]=xyz[1]+1;
                pu[2]=xyz[2]+1;
                q.push(pu);
                m[xyz[0]][xyz[1]+1]=pu[2];
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}