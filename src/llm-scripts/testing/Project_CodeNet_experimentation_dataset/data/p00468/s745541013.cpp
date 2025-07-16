#include<bits/stdc++.h>
using namespace std;
    long long stu[510],memo[510][510],m,n,sum,a,b;
int main(){


    while(1){

    cin >> n >> m;
    if(n==0)break;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(a==1&&stu[b]==0){
            stu[b]=1;
            sum++;
        }else memo[a][b]=5;
    }

    for(int i=2;i<n+1;i++){
        for(int j=2;j<n+1;j++){

            if(memo[i][j]==5){
                if(stu[i]==1&&stu[j]==0){
                        stu[j]=2;
                        sum++;
                }
            }

        }
    }
    for(int i=2;i<n+1;i++){
        for(int j=2;j<n+1;j++){

            if(memo[i][j]==5){
                if(stu[i]==0&&stu[j]==1){
                        stu[i]=2;
                        sum++;
                }
            }

        }
    }

     cout << sum << endl;

     for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            memo[i][j]=0;
        }
     }
     for(int i=0;i<n+1;i++){
            stu[i]=0;
     }
     sum=0;

    }
return 0;
    }