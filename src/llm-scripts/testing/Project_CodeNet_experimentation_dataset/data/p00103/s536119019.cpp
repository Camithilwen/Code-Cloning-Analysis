#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() 
{
    int n;
    scanf("%d",&n);
    for (int ix=0; ix<n; ix++) {
        int out=0,score=0;
        int hit[] = {0,0,0};
        string event;
        while (out<3) {
            cin>>event;
            if (event=="HIT") {
                if (hit[2]==1) score++;
                if (hit[1]==1) hit[2]=1;
                if (hit[0]==1) hit[1]=1;
                hit[0]=1;
            }
            else if (event=="HOMERUN") {
                for (int i=0; i<3; i++) {
                    score+=hit[i];
                    hit[i]=0;
                }
                score++;
            }
            else if (event=="OUT") {
                out++;
            }
        }
        printf("%d\n",score);
    }
}