#include<bits/stdc++.h>
using namespace std;
#define INF (1<<29)//INF
#define F first
#define S second
#define VS vector<string>
#define VI vector<int>
#define REPI(i,s,n) for(int i=s;i<n;i++)//sからn未満の間iを回す
#define REPJ(j,s,n) for(int j=s;j<n;j++)//sからn未満の間iを回す
#define RREPI(i,s,n) for(int i=s;i>=n;i--)//sからn以下の間iを回す
#define RREPJ(j,s,n) for(int j=s;j>=n;j--)//sからn以下の間jを回す
#define ALL(a) a.begin(),a.end()//ソートとかに使える sort(ALL(vec))のように
#define SET(a,c) memset(a,c,sizeof(a));//aをc（0or1）で初期化する
#define DEBUGONE(x) cout<<#x<<" : "<<x<<endl;//デバックで一つの変数を表示
#define DEBUGTWO(x,y) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl;//デバックで二つの変数を表示
#define DEBUGTHREE(x,y,z) cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl;//デバックで三つの変数を表示
#define OUTONE(x) cout<<x<<endl;//一つの変数を表示
#define OUTTWO(x,y) cout<<x<<" "<<y<<endl;//二つの変数を表示
#define OUTTHREE(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;//三つの変数を表示
typedef long long int64;
typedef pair<string,int> Psi;
typedef pair<int,int> Pii;
map<Psi,int64> mem;
string num[15];
int n,k;
int64 ans=0;
int64 bitdfs(int now,string nows,int bits);
main(){
  while(cin>>n>>k,n||k){
    ans=0;
    mem.clear();
    REPI(i,0,n){
      cin>>num[i];
    }
    cout<<bitdfs(0,"",0)<<endl;
  }
}
int64 bitdfs(int now,string nows,int bits){
  if(now>=k){
    if(mem[Psi(nows,now)]==0){
      mem[Psi(nows,now)]=-1;
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    int64 cnt=0;
    int bitst=1;
    REPI(i,0,n){
      int b=bitst&bits;
      if(b==0){
	cnt+=bitdfs(now+1,nows+num[i],bits|bitst);
      }
      bitst=bitst<<1;
    }
    return mem[Psi(nows,now)]=cnt;
  }
}