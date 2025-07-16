#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int m,n;
    while(cin>>n>>m,n){
        int plz[1050]={0},total=0,cnt=1;
        for(int i=0;i<n;i++){
            cin>>plz[i];
        }
        sort(plz,plz+n);
        reverse(plz,plz+n);
        for(int i=0;i<n;i++){
            if(cnt!=m){
                total+=plz[i];
                cnt++;
            }
            else if(cnt==m){
                    cnt=1;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}