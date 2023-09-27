#include<iostream>

//??°??¢(0??§???????????????1??§??????)
int place[21][21]={};

//??????????????°??¨??????????????°
int N,M;

//???????????????
int mass;
char dir[10];

int main() {
	while (true) {
		//?????????
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				place[i][j] = 0;
			}
		}
		//????????\???
		std::cin>>N;
		if(N==0)break;
		for (int i = 0; i < N; i++) {
			int x,y;
			std::cin>>x>>y;
			place[y][x]=1;
		}
		//????????????(?????????(10,10))
		int rX=10;
		int rY=10;
		std::cin >> M;
		for (int i = 0; i < M; i++) {
			std::cin >> dir >> mass;
			//???????????????
			int dirX,dirY;
			switch (dir[0]) {
			case 'N': dirX=0; dirY=1 ; break;
			case 'S': dirX=0; dirY=-1; break;
			case 'E': dirX=1; dirY=0 ; break;
			case 'W': dirX=-1;dirY=0 ; break;
			}
			for (int i = 0; i < mass; i++) {
				rX+=dirX;
				rY+=dirY;
				place[rY][rX]=0;
			}
		}
		//place??¨??????0??????ok
		bool flag=true;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				if(place[i][j]!=0)flag=false;
			}
		}
		if (flag)std::cout << "Yes" << std::endl;
		else     std::cout << "No"  << std::endl;
	}


	return 0;
}