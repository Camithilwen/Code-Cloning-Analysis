#include<bits/stdc++.h>
using namespace std;
int main(void){
    string S;
    int counter=0;
    cin>>S;

    for(int i=0;i<3;i++){
        if(S[i]=='R'){
            counter++;
            for(int j=1;j<3;j++){
                if(S[i+j]=='R'){
                    counter++;
                    if(j==2){
                        cout<<counter<<endl;
                        return 0;
                    }
                }else{
                    cout<<counter<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<counter<<endl;


    return 0;
}