#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=502;
int n,ar[N][N],lis[1006],dx[]={0,0,-1,1},dy[]={-1,1,0,0},ar1[N][N];
bool check(int x,int y){
  if(x>0&&x<=n){
    if(y>0&&y<=n){
      return true;
    }
  }
  return false;
}
bool check1(int x){
    int i;
    for(i=2;i*i<=x;i++){
     if(x%i==0){
         return false;
     }
    }
    return true;
}
int LCM(int x,int y){
  return (x/__gcd(x,y)) * y;
}
signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i,j,k,l,num=0,hichic=0;
  cin>>n;
  if(n==2){
    cout<<"4 7\n23 10";
    return 0;
  }
  for(i=2;i<=10000;i++){
    //cout<<i<<endl;
        if(check1(i)){
        num++;
         lis[num]=i;
      //cout<<num<<' '<<i<<endl;
          if(num==1002){
        //cout<<num<<' '<<"cac"<<endl;
                break;
            }
        }
    }
    //cout<<num<<endl;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(!((i+j)&1)){
          continue;
        }
        if(i-1&&j-1){
          ar[i][j]=ar[i-1][j-1];
        }
        else{
          hichic++;
          ar[i][j]=lis[hichic];
        }
      }
    }
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(!((i+j)&1)){
          continue;
        }
        if(i-1&&j+1<=n){
    		ar1[i][j]=ar1[i-1][j+1];
          	ar[i][j]*=ar1[i][j];
        }
        else{
          hichic++;
          ar[i][j]*=lis[hichic];
          ar1[i][j]=lis[hichic];
        }
      }
    }
    //cout<<"cac"<<endl;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(!((i+j)&1)){
          ar[i][j]=1;
          for(l=0;l<4;l++){
            if(check(i+dx[l],j+dy[l])){
              ar[i][j]=LCM(ar[i][j],ar[i+dx[l]][j+dy[l]]);
            }
          }
          cout<<ar[i][j]+1<<' ';
        }
        else{
            cout<<ar[i][j]<<' ';
        }
      }
      cout<<'\n';
    }
}