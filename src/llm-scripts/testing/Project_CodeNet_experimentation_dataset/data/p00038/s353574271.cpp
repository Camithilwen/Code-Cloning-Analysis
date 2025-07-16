#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    while(cin>>num){
        char str;
        int hand[14]={};
        hand[num]++;
        for(int i=0;i<4;i++){
            cin>>str>>num;
            hand[num]++;
        }
        bool four=0,three=0,two[2]={};
        for(int i=1,j=0;i<14;i++){
            if(hand[i]==4)four=1;
            else if(hand[i]==3)three=1;
            else if(hand[i]==2){
                two[j]=1;
                j++;
            }
        }
        if(four)cout<<"four card"<<endl;
        else if(three&&two[0])cout<<"full house"<<endl;
        else if(three)cout<<"three card"<<endl;
        else if(two[1])cout<<"two pair"<<endl;
        else if(two[0])cout<<"one pair"<<endl;
        else{
            bool kawa=0;
            for(int i=1;i<=10;i++){
                if(hand[i]==1){
                    for(int j=0;j<5;j++){
                        if(j+i>13&&hand[1]!=1)break;
                        else if(j+i<14&&hand[i+j]!=1)break;
                        if(j==4)kawa=1;
                    }
                }
            }
            if(kawa)cout<<"straight"<<endl;
            else cout<<"null"<<endl;
        }

    }
}