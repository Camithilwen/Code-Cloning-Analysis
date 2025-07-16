#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000000

int map[100][100];
int n,k,cou,tmin;
int dd[101],col[100];

int main(){
  int t,a,b,c,d,e;
  cin >> n >> k;
  while(n!=0&&k!=0){
    for (int i=0;i<10000;i++)map[i/100][i%100]=0;
    for (int i=0;i<k;i++){
      cin >> t;
      //      for (int y=0;y<k;y++){
      //for (int x=0;x<k;x++)
      //  cout << map[y][x] << " ";
      //cout << endl;
      //}
      if (t == 0){
	cin >> a >> b;
	for (int j=0;j<101;j++)dd[j]=INF;
	for (int j=0;j<101;j++)col[j]=0;
	dd[a-1]=0;
	cou = 1;
	col[a-1]=1;
	for (int m=0;m<n;m++)
	  if(map[a-1][m]>0)
	    dd[m]=min(dd[m],dd[a-1]+map[a-1][m]);

	while (cou < n){
	  tmin=100;
	  for (int m=0;m<n;m++) 
	    if (col[m]==0)
	      if (dd[tmin]>dd[m]) tmin = m;

	  // for (int m=0;m<n;m++)cout << dd[m] << " ";//Dbg
	  // cout << endl;//Dbg

	  col[tmin]=1;
	  cou ++;

	  for (int m=0;m<n;m++)
	    if(map[tmin][m]>0)
	      dd[m]=min(dd[m],dd[tmin]+map[tmin][m]);
	}
	if (dd[b-1]==INF)cout << -1 << endl;
	else cout << dd[b-1] <<endl;
      }else{
	cin >> c >> d >> e;
	c--;d--;
	if (map[c][d]==0){
	  map[c][d]=e;
	  map[d][c]=e;
	}
	map[c][d]=min(map[c][d],e);
	map[d][c]=min(map[d][c],e);
      }
    }
    cin >> n >> k;
  }
  return 0;
}