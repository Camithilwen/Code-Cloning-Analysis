#include<iostream>
#include<cstdlib>
#include<queue>
#define MAX 22
#define BLOCK 1
#define START 2
#define GOAL 3
#define REP(i,a,e) for(int i=(a);i<=(e);++i)
#define REPD(i,a,e) for(int i=(a);i>=(e);--i)
using namespace std;
struct Map{
	Map(){
		REP(i,0,MAX-1)REP(j,0,MAX-1)map[i][j]=0;
	}
	int h,w;
	char map[MAX][MAX];
	int depth;
	pair<int, int> stone;
};
int BFS(Map &m){
	queue<Map> q;
	
	q.push( m );
	while( !q.empty() ){
		Map t = q.front();
		q.pop();

		/* up */
		REPD(i,t.stone.first,0){
			if( t.map[i][ t.stone.second ] == BLOCK ){
				if( abs(i-t.stone.first) > 1 ){
					Map tt = t;
					tt.map[ i ][ t.stone.second ] = 0;
					tt.stone = make_pair( i + 1, t.stone.second );
					if( ++tt.depth < 10 )
						q.push( tt );
				}
				break;
			}else if( t.map[i][ t.stone.second ] == GOAL ){
				return t.depth+1;
			}
		}
		/* down */
		REP(i,t.stone.first,t.h+1){
			if( t.map[i][ t.stone.second ] == BLOCK ){
				if( abs(i-t.stone.first) > 1 ){
					Map tt = t;
					tt.map[ i ][ t.stone.second ] = 0;
					tt.stone = make_pair( i - 1, t.stone.second );
					if( ++tt.depth < 10 )
						q.push( tt );
				}
				break;
			}else if( t.map[i][ t.stone.second ] == GOAL ){
				return t.depth+1;
			}
		}
		/* right */
		REP(j,t.stone.second,t.w+1){
			if( t.map[ t.stone.first ][ j ] == BLOCK ){
				if( abs(j-t.stone.second) > 1 ){
					Map tt = t;
					tt.map[ t.stone.first ][ j ] = 0;
					tt.stone = make_pair( t.stone.first, j - 1 );
					if( ++tt.depth < 10 )
						q.push( tt );
				}
				break;
			}else if( t.map[ t.stone.first ][ j ] == GOAL ){
				return t.depth+1;
			}
		}
		/* left */
		REPD(j,t.stone.second,0){
			if( t.map[ t.stone.first ][ j ] == BLOCK ){
				if( abs(j-t.stone.second) > 1 ){
					Map tt = t;
					tt.map[ t.stone.first ][ j ] = 0;
					tt.stone = make_pair( t.stone.first, j + 1 );
					if( ++tt.depth < 10 )
						q.push( tt );
				}
				break;
			}else if( t.map[ t.stone.first ][ j ] == GOAL ){
				return t.depth+1;
			}
		}
	}
	return -1;
}
int main(){
	while(true){
		Map m;
		scanf("%d%d", &m.w, &m.h);
		if( m.w==0 && m.h==0 )break;

		REP(i,1,m.h)REP(j,1,m.w){
			scanf("%d", &m.map[i][j]);
			if( m.map[i][j] == START ){
				m.stone=make_pair(i,j);
			}
		}
		m.depth = 0;

		printf("%d\n", BFS( m ));
	}
}