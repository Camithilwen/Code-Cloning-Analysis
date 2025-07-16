#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w,h;
int sx,sy,gx,gy;
int field[104][104];

class Info{
public:
	int x,y;
};

bool bfd(void){
	int search = field[sy-1][sx-1];
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};

	queue<Info> q;
	Info tmp = {sx-1,sy-1};

	if(search == 0){return false;}

	q.push(tmp);
	while(!q.empty()){
		tmp = q.front(); q.pop();

		if(tmp.x + 1 == gx && tmp.y + 1 == gy){
			return true;
		}

		field[tmp.y][tmp.x] = 0;
		for(int k=0;k<4;k++){
			int nx = tmp.x + dx[k];
			int ny = tmp.y + dy[k];

			if(nx>=0 && ny>=0 && nx<w && ny<h && field[ny][nx]==search){
				Info tmp2 = {nx,ny};
				q.push(tmp2);
			}
		}
	}

	return false;
}

void put_block(int c,int d,int x,int y){
	int i,j;
	int to_i=2,to_j=4;

	if(d == 1){to_i=4,to_j=2;}

	for(i=0;i<to_i;i++){
		for(j=0;j<to_j;j++){
			field[y+i-1][x+j-1] = c;
		}
	}
}

int main(void){
	int n,c,d,x,y;

	while(cin>>w>>h && w){
		cin>>sx>>sy>>gx>>gy>>n;

		memset(field,0,sizeof(field));
		while(n--){
			cin>>c>>d>>x>>y;
			put_block(c,d,x,y);
		}

		if(bfd()){
			cout<<"OK\n";
		}
		else{
			cout<<"NG\n";
		}
	}

	return 0;
}