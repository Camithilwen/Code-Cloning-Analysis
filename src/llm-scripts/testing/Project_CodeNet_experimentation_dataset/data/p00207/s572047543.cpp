#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <map> 
#include <sstream>
#include <cstdio>
#include <complex>
#include <cstring>
using namespace std;
 
const int MAX= 10000100;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
#define ll long long int
#define gcd(a,b) __gcd(a,b)
#define pb(a) push_back(a)
int GCD(int a, int b) {if(!b) return a; return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}

int m[100][100];
int sx,sy,gx,gy;
int w,h;
bool dfs(int x,int y,int c){
  if(x==gx&&y==gy)return true;
  if(m[y][x] == 0)return false;
  m[y][x] = 0;
  //cout<<x<<" "<<y<<" "<<c<<endl;
  int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
  bool judge=false;
  rep(i,4){
    if(m[y+dy[i]][x+dx[i]] == c)
      judge |= dfs(x+dx[i],y+dy[i],c);
  }
  return judge;
}


int main(void){
  while(cin>>h>>w,h+w){
    rep(i,h)rep(j,w)m[i][j]=0;
  
    cin>>sx>>sy>>gx>>gy;
 
    int n,c,d,x,y;
    cin>>n;
    rep(i,n){
      cin>>c>>d>>x>>y;
      //cout<<c<<" "<<d<<" "<<x<<" "<<y<<endl;
      if(d){
	rep(i,4)rep(j,2)m[i+y][j+x] = c;
      }else{
	//cout<<x<<" "<<y<<endl;
	rep(i,2)rep(j,4)m[i+y][j+x] = c;      
      }
    }
    //m[sy][sx] = 8; m[gy][gx] = 9;
    //cout<<"  ";rep(i,w)cout<<i%10<<" ";cout<<endl;
    //rep(i,h){cout<<i%10<<" ";rep(j,w)cout<<m[i][j]<<" ";cout<<endl;}
    cout<<(dfs(sx,sy,m[sy][sx])?"OK":"NG")<<endl;
  }
}