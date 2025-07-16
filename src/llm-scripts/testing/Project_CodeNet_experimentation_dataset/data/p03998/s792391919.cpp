#include<iostream>
#include<string>

using namespace std;
int main(){
    string a,b,c;
    int ca=0,cb=0,cc=0,flag=0,ans=0;
    cin>>a>>b>>c;

    for(int i=0;i<a.size()+b.size()+c.size();i++){
        if(flag==0){
             if(ca==a.size()){
                ans=1;
                break;
            }

            if(a[ca]=='a')flag=0;
            if(a[ca]=='b')flag=1;
            if(a[ca]=='c')flag=2;

            ca++;
        }

        else if(flag==1){
             if(cb==b.size()){
                ans=2;
                break;
            }
            
            if(b[cb]=='a')flag=0;
            if(b[cb]=='b')flag=1;
            if(b[cb]=='c')flag=2;

            cb++;
        }

        else if(flag==2){
            if(cc==c.size()){
                ans=3;
                break;
            }    

            if(c[cc]=='a')flag=0;
            if(c[cc]=='b')flag=1;
            if(c[cc]=='c')flag=2;
        
            cc++;
        }
    }

    if(ans==1)cout<<"A"<<endl;
    if(ans==2)cout<<"B"<<endl;
    if(ans==3)cout<<"C"<<endl;

    return 0;
}