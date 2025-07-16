#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#include<map>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

typedef unsigned int uint;
typedef long long ll;

using namespace std;

char buff[12][13];
int  cl[12][12];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void check(int x, int y, int c){
  if(buff[y][x] == '0') return;
  if(cl[y][x] != 0) return;
  if(y < 0) return;
  if(x < 0) return;
  if(y > 11) return;
  if(x > 11) return;
  cl[y][x] = c;
  REP(i,4)
    check(x+dx[i],y+dy[i],c);
}

int main(){
  while(cin>>buff[0]){
    REP(i,11)
      cin>>buff[i+1];

    memset(cl,0,sizeof(cl));
    int cnt = 1;
    REP(i,12) REP(j,12){
      if(cl[i][j] == 0 && buff[i][j] == '1')
        check(j,i,cnt++);
    }

    /*
    REP(i,12){ REP(j,12)
        printf("%2d ",cl[i][j]); puts("");}
    */
    cout << cnt-1 << endl;
  }
  return 0;
}