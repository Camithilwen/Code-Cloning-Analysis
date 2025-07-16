#include<iostream>
#include<algorithm>
#include<utility>

#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define P pair<int, int>

using namespace std;

char field[12][12];
int cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char depth;

void dfs(int x,int y){
	/*
	rep(i, 12){
		rep(j, 12){
			
			if (field[i][j] == '1'){
				cout << field[i][j];
			}
			else{
				cout << field[i][j];
			}

			if (j == 11){
				cout << endl;
			}
		}
	}
	cout << endl;
	*/

	field[x][y] = '0';
	rep(i, 4){		
		int ddx = x + dx[i], ddy = y + dy[i];
		if (0<=ddx && ddx<12 && 0<=ddy && ddy<12 && field[ddx][ddy] == '1'){
			dfs(ddx, ddy);
		}
		
	}
	

}


int main(){
	while (1){
		cnt = 0;
		rep(i, 12){
			rep(j, 12){
				char c;
				cin >> c;
				if(cin.eof()){
					return 0;
				}
				field[i][j] = c;
				/*if (j == 11){
					char EnTeR;
					cin >> EnTeR;
				}*/
			}
		}

		/*
		rep(i, 12){
			rep(j, 12){
				if (field[i][j] == '1'){
					cout << "テ「ツ鳴?;
				}
				else{
					cout << "テ「ツ鳴。";
				}

				if (j == 11){
					cout << endl;
				}
			}
		}
		*/


		rep(i, 12){
			rep(j, 12){
				if (field[i][j] == '1'){
					cnt++;
					dfs(i, j);
				}
			}
		}

		cout << cnt << endl;



	}

	
}