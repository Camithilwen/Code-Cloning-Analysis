#include <iostream>
#include <string>
using namespace std;

string ans;
int w,h,gx,gy;
int map[110][110];
int dx_[4] = {0,1,0,-1};
int dy_[4] = {1,0,-1,0};
int dx[2][8] = {
	{0,1,2,3,0,1,2,3},
	{0,1,0,1,0,1,0,1}
};
int dy[2][8] = {
	{0,0,0,0,1,1,1,1},
	{0,0,1,1,2,2,3,3},
};
void solve(int x,int y,int color){
	if( ans == "OK" || color == 0 /*|| map[y][x] != color*/ ) return;
	//if( x<0 || x>w || y<0 || y>h ) return;

	for(int i=0 ; i<4 ; ++i ){
		int mx = x + dx_[i];
		int my = y + dy_[i];
		if( mx<0 || mx>w || my<0 || my>h ) continue;
		//cout << "x:" << x << " y:" << y << endl;
		
		if( map[my][mx] == color ){
			if( mx == gx && my == gy ){
				ans = "OK";
			}else{
				map[my][mx] = 0;
				solve( mx , my , color );
			}
		}
	}
}

void debug(){
	char c[6] = {' ','#','$','*','+','@'};
	cout << "w:" << w << " h:" << h << " map : " << endl;
	for(int y=0 ; y<h ; ++y ){
		for(int x=0 ; x<w ; ++x ){
			cout << c[ map[y][x] ];
		}
		cout << endl;
	}
}

int main(){
	int sx,sy,n;
	
	while( cin >> w >> h , w|h ){
		ans = "NG";
		for(int y=0 ; y<110 ; ++y )
			for(int x=0 ; x<110 ; ++x )
				map[y][x] = 0;

		cin >> sx >> sy >> gx >> gy >> n ;
		for(int i=0 ; i<n ; ++i ){
			int c,d,x,y;
			cin >> c >> d >> x >> y;
			for(int j=0 ; j<8 ; j++){
				int mx = x + dx[d][j];
				int my = y + dy[d][j];
				map[my][mx] = c;
			}
		}
		//debug();
		//map[sy][sx] = 0;
		solve( sx , sy , map[sy][sx] );
		//cout << "sx:" << sx << " sy:" << sy << endl;
		cout << ans << endl;
	}
}