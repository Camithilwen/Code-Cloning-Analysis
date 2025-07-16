#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        int out=0,score=0,base=0;
        while(out<3){
            cin>>s;
            if(s=="HIT"){
                base++;
                if(base>3){
                    score+=base%3;
                    base-=base%3;
                }
            }
            if(s=="HOMERUN"){
                score+=base+1;
                base=0;
            }
            if(s=="OUT"){
                out++;
            }
        }
        cout<<score<<endl;;
        
    }
}