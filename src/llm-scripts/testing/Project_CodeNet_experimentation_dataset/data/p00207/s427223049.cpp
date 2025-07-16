#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef pair<int,int> P;
const int MAX = 120;

int maze[MAX][MAX];
bool come[MAX][MAX];
P s,g;
int W,H,c;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

void init(){
  memset(come,false,sizeof(come));
  memset(maze,0,sizeof(maze));
}


void input_B(){
  int n;
  cin >> n;
  while(n--){
    int c,d,x,y;
    cin >> c >> d >> x >> y;
    if(d){
      for(int i = y; i < y+4; i++)
	for(int j = x; j < x+2; j++)
	  maze[i][j] = c;
    }else{
      for(int i = y; i < y+2; i++)
	for(int j = x; j < x+4; j++)
	  maze[i][j] = c;
    }
  }
}


void solve(P p){
  
  if(come[p.second][p.first] == false){
    come[p.second][p.first] = true;
    for(int i = 0; i < 4; i++)
      if(0 < p.first+dx[i] && p.first+dx[i] <= W &&
	 0 < p.second+dy[i] && p.second+dy[i] <= H &&
	 maze[p.second+dy[i]][p.first+dx[i]] == c) solve(P(p.first+dx[i],p.second+dy[i]));
  }
}

void print(){
  for(int i = 1; i < H; i++){
    for(int j = 1; j < W; j++)// cout << come[i][j];
      cout << maze[i][j];
    cout << endl;
  }

}


int main(){
  while(cin >> W >> H && W+H){
    init();
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    input_B();
    c = maze[s.second][s.first];
    solve(s);
    //print();
    if(come[g.second][g.first] && c) cout << "OK" << endl;
    else cout << "NG" << endl;
  }
  return 0;
}