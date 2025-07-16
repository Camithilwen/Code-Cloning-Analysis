#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n){
        string action;
        int base=0,outCount=0,point=0;
        while(outCount!=3){
            cin>>action;
            if(action=="OUT"){
                outCount++;
            }
            else if(action=="HIT"){
                base++;
                if(base==4){
                    point++;
                    base--;
                }
            }
            else if(action=="HOMERUN"){
                point += base+1;
                base=0;
            }
        }
        cout<<point<<endl;
        n--;
    }
    return 0;
}