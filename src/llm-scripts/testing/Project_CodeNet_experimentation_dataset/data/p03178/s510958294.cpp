#include<iostream>
#include<string>
using namespace std;

long long MOD = 1000000007;

int  main(){
    //input
    long long D;
    string S;
    cin >> S;
    cin >> D;
    long long keta=S.length();
    long long N[keta];
    long long i,k, digit;
    long long j;
    for(i=0; i<keta; i++){
        N[i]=(long long)(S[i]-'0');
    }

    //calc
    long long dp[keta][2][D];
    for(i=0; i<keta; i++){
        for(j=0; j<=1; j++){
            for(k=0; k<D; k++){
                dp[i][j][k]=0;
            }
        }
    }
    for(digit=0; digit<10; digit++){
        if(digit<N[0]){
            dp[0][1][digit%D]++; 
        }else if(digit==N[0]){
            dp[0][0][digit%D]++;
        }
    }
    for(i=0; i<keta-1; i++){
        for(j=0; j<=1; j++){
            for(k=0; k<D; k++){
                for(digit=0; digit<(j?10:N[i+1]+1); digit++){
                    dp[i+1][j||(digit<N[i+1])][(k+digit)%D]+=dp[i][j][k];
                    dp[i+1][j||(digit<N[i+1])][(k+digit)%D]%=MOD;
                }
            }
        }
    }

    cout << (dp[keta-1][0][0]+dp[keta-1][1][0]-1+MOD)%MOD << endl;
    system("pause");
    return 0;
}