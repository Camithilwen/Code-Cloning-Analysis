#include<iostream>
#include<string>
using namespace std;
string map[20]={""};
void check(int x,int y);
int main(void){
    while(1){
        int ans=0;
        for(int i=0;i<12;i++){
            cin>>map[i];
            if(cin.eof())goto end;
        }
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                if(map[i][j]=='1'){
                    check(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    end:;
    return 0;
}
void check(int x,int y){
    map[x][y]='0';
    if(x!=11&&map[x+1][y]=='1')check(x+1,y);
    if(y!=11&&map[x][y+1]=='1')check(x,y+1);
    if(x!=0&&map[x-1][y]=='1')check(x-1,y);
    if(y!=0&&map[x][y-1]=='1')check(x,y-1);
    return;
}