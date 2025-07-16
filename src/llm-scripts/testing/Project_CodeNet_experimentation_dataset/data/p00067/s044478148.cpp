//こんなプログラムを組んではいけない(戒め
//マージの仕様が複雑だし、空白マスを引く処理忘れやすいし、ひどいコードだ。
#include<iostream>
#include<queue>
using namespace std;

const int h = 12;
const int w = 12;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

char data[h][w+2];

//データ構造をマージする一般的なテクなし。
class UnionFind {
public:
	int oya[2521], size;
	void ini(int size) { this->size = size; for( int i = 0;i < size; i++ ) oya[i] = i; }
	int root(int x) { if( oya[x] == x ) return x; return (oya[x] = root(oya[x]) ); }
	void marge(int x, int y) { x = root(x); y = root(y); if ( x != y ) { size--; oya[x] = y; } }
}uf;

void bfs(int sy, int sx) {
	queue<int> que;
	que.push(sy*w + sx);
	
	while( !que.empty() ) {
		int now = que.front();
		que.pop();
		
		if ( data[now/w][now%w] == '0' )
			continue;
		if ( uf.root(now) != now ) 	//すでに調べている(マージされている)ならcontinue
			continue;
		
		uf.marge(now, sy*w + sx);	//nowをsy*w + sxにくっつける(逆にしたら無限ループするかも)
		
		for(int i = 0; i < 4; i++ ) {
			int ny = now/w + dy[i];
			int nx = now%w + dx[i];
			if ( 0 <= ny && ny < h && 0 <= nx && nx < w )
				que.push(ny * w + nx);
		}
	}
}

int main() {
	int i, j;
	while( cin >> data[0] ) {
		for( i = 1; i < h; i++ )
			cin >> data[i];
		
		uf.ini(h*w);
		
		int minus = 0;
		for( i = 0; i < h; i++ ) {
			for( j = 0; j < w; j++ ) {
				minus += (data[i][j] == '0');
				bfs(i, j);
			}
		}
		cout << uf.size - minus << endl;
	}
	return 0;
}