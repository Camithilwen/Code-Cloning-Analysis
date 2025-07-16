#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    int count,box,random,a=0,b=0,i,j,k,n,dice[100][6];

    cin >> n;

    for(i=0;i<n;i++){
        for(j=0;j<6;j++){
            cin >> dice[i][j];
        }
    }

    for(k=1;k<n;k++){
        if(b==1){
            break;
        }
         for(i=0;i<10000;i++){
             count=0;
             if(a==1){
                 b=1;
                 break;
             }
             for(int j=0;j<6;j++){
                 if(dice[0][j] == dice[k][j]){
                     count++;
                 }
             }
             if(count==6){
                 cout << "No" << endl;
                 a=1;
                 break;
             }
             
             random = rand() % 4 + 1;
             
             if(random == 1){
                 box=dice[k][0];
                 dice[k][0]=dice[k][4];
                 dice[k][4]=dice[k][5];
                 dice[k][5]=dice[k][1];
                 dice[k][1]=box;
             }
             else if(random == 2){
                 box=dice[k][0];
                 dice[k][0]=dice[k][1];
                 dice[k][1]=dice[k][5];
                 dice[k][5]=dice[k][4];
                 dice[k][4]=box;
             }
             else if(random == 3){
                 box=dice[k][0];
                 dice[k][0]=dice[k][2];
                 dice[k][2]=dice[k][5];
                 dice[k][5]=dice[k][3];
                 dice[k][3]=box;
             }
             else if(random == 4){
                 box=dice[k][0];
                 dice[k][0]=dice[k][3];
                 dice[k][3]=dice[k][5];
                 dice[k][5]=dice[k][2];
                 dice[k][2]=box;
             }
         }
    }
    
         if(a!=1){
             cout << "Yes" << endl; 
         }
    
    return 0;
}