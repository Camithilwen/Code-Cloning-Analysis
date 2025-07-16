#include <bits/stdc++.h>
using namespace std;
char a[6][6]={"aacd","bbcd","cdaa","cdbb"};
char b[8][8]={"aabba","bcc.a","b..cb","a..cb","abbaa"};
char c[8][8]={"bbacc.","a.a..c","abb..c","cc.bba","..ca.a","..cabb"};
char d[9][9]={"eeffee.","aa.aa.e","..a..ae","..a..af","aa.aa.f","..a..ae","..a..ae"};
char ans[1002][1002];
void f(int n,int k){
    if(n==1)return;
    int i,j;
    char q='a';
    char w='b';
    if(k%2)q='c',w='d';
    char c=q;
    for(i=1 ; i<n ; i+=2){
        a[k][i-1+k]=a[k][i+k]=c;
        if(c==q)c=w;
        else c=q;
    }
    for(i=1 ; i<n ; i+=2){
        a[i+k][n-1+k]=a[i-1+k][n-1+k]=c;
        if(c==q)c=w;
        else c=q;
    }
    for(i=n-1 ; i>=1 ; i-=2){
        a[n-1+k][i+k]=a[n-1+k][i+k-1]=c;
        if(c==q)c=w;
        else c=q;
    }
    for(i=n-1 ; i>=1 ; i-=2){
        a[i+k][k]=a[i-1+k][k]=c;
        if(c==q)c=w;
        else c=q;
    }
    f(n-2,k+1);
}
void check(int n){
    int i,j;
    int s=0;
    for(i=0 ; i<n ; i++){
        if(a[0][i]!='.' && a[0][i]!=a[0][i+1])s++;
    }
    for(i=0 ; i<n ; i++){
        int cnt=0;
        for(j=0 ; j<n ; j++){
            if(a[i][j]!='.' && a[i][j]!=a[i][j+1])cnt++;
        }
        if(cnt!=s)cout<<"!";
    }
    for(i=0 ; i<n ; i++){
        int cnt=0;
        for(j=0 ; j<n ; j++){
            if(a[j][i]!='.' && a[j+1][i]!=a[j][i])cnt++;
        }
        if(cnt!=s)cout<<"!";
    }
}
int main(){
    cin.tie(0);
    int n;
    ios_base::sync_with_stdio(0);
    cin>>n;
    int i,j;
    int k=0;
    int m=n;
    if(n==2 ){
        cout<<-1;
        return 0;
    }
    if(n==7){
        for(i=0 ; i<7 ; i++)cout<<d[i]<<endl;
        return 0;
    }
    if(n==3){
        cout<<"aa."<<endl<<"..a"<<endl<<"..a";
        return 0;
    }
    while(n){
        if(n==11){
            n-=5;
            for(i=0 ; i<5 ; i++){
                for(j=0 ; j<5 ; j++){
                    ans[n+i][n+j]=b[i][j];
                }
            }
            n-=6;
            for(i=0 ; i<6 ; i++){
                for(j=0 ; j<6 ; j++)
                    ans[i][j]=c[i][j];
            }
            break;
        }
        if(n==5){
            n-=5;
            for(i=0 ; i<5 ; i++){
                for(j=0 ; j<5 ; j++){
                    ans[i][j]=b[i][j];
                }
            }
            break;
        }
        if(n==6){
            n-=6;
            for(i=0 ; i<6 ; i++){
                for(j=0 ; j<6 ; j++)
                    ans[i][j]=c[i][j];
            }
            break;
        }
        n-=4;
        for(i=0 ; i<4 ; i++){
            for(j=0 ; j<4 ; j++){
                ans[n+i][n+j]=a[i][j];
            }
        }
    }

    for(i=0 ; i<m ; i++){
        for(j=0 ; j<m ; j++){
            if(ans[i][j]==0)cout<<'.';
            else cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
