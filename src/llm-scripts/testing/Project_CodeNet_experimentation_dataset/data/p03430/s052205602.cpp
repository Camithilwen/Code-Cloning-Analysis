#include<bits/stdc++.h>
#define dro first
#define adg second.first
#define mog second.second
#define ll long long
using namespace std;

const int N = 500001;

int n,r,pos,l,x,U,D,S;
 
long long ans;
int K;

string s;

int fix[100],fix1[100],A[100],B[100];

int dp[305][305][305];

int main(){
    
    cin>>s;
    
    n=s.size();
    
    cin>>K;
    
    for(int j=0;j<n;j++)
    for(int l=0;l+j<n;l++)
    for(int k=0;k<=K;k++){
        
        int r = l+j;
        
        if(l==r){
            dp[l][r][k] = 1;
            continue;
            //dp[l][r][1] = 1
        }

        if(l+1==r){
            if(k==0){
                dp[l][r][k] = 1;
                if(s[l] == s[r]) dp[l][r][k] = 2;
            } else {
                dp[l][r][k] = 2;
            }
            
            continue;
        }
        
        dp[l][r][k] = max( dp[l+1][r][k], dp[l][r-1][k]);
        //cout<<dp[l+1][r][k]<<" "<<l<<" "<<r<<" "<<k<<endl;
        //cout<<dp[l][r-1][k]<<" "<<l<<" "<<r<<" "<<k<<endl;
        if(s[l]==s[r])
            dp[l][r][k] = max( dp[l][r][k], dp[l+1][r-1][k] + 2);
        else {
            if(k-1>=0)
            dp[l][r][k] = max( dp[l][r][k], dp[l+1][r-1][k-1] + 2);
        }

        //cout<<dp[l][r][k]<<" "<<l<<" "<<r<<" "<<k<<endl;
    }
    
    cout<<dp[0][n-1][K]<<endl;
}



