#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int cards[5];
    char dummy;
    while (cin>>cards[0]>>dummy>>cards[1]>>dummy>>cards[2]>>dummy>>cards[3]>>dummy>>cards[4])
    {
        int count=0,ans=0;
        sort(cards,cards+5);
        for (int i=0; i<4; i++)
        {
            if ( cards[i] == cards[i+1] )
            {
                count++;
                ans+=count;
            }
            else count=0;
        }
        
        if (ans==0)
        {
            int sum=0;
            for (int i=0; i<5; i++) sum+=cards[i];
            if(sum-cards[0]*5==10) puts("straight");
            else if(cards[0]==1 && cards[1]==10 && cards[2]==11 && cards[3]==12 && cards[4]==13) puts("straight");
            else puts("null");
        }
        
        else if (ans==1) puts("one pair");
        else if (ans==2) puts("two pair");
        else if (ans==3) puts("three card");
        else if (ans==4) puts("full house");
        else if (ans==6) puts("four card");
        
    }
    return 0;
}