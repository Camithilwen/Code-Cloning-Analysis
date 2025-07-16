#include <iostream>
using namespace std;

int F[102][102];
int xg,yg,ok;

void Maze(int X,int Y,int C){
	//cout << X<<Y<<F[X][Y]<<endl;
	if(F[X][Y]!=C)
		return;

	

	if(X==xg&&Y==yg){
		cout << "OK"<<endl;
		ok++;
	}

	F[X][Y]='.';

	Maze(X-1,Y  ,C);
	Maze(X  ,Y+1,C);
	Maze(X+1,Y  ,C);
	Maze(X  ,Y-1,C);
	
}



int main(){	
	while(1){
		ok=0;
		for(int i=1; i<=100; i++)
			for(int j=1; j<=100; j++)
				F[j][i]=0;


		for(int i=0; i<102;i++){
			F[0][i]=6;
			F[i][0]=6;
		}


		int w,h,xs,ys,n,c,d,x,y;

		cin >>w>>h;
		if(w==0&&h==0)
			return 0;

		cin >>xs>>ys;
		cin >>xg>>yg;
		cin >>n;



		for(int i=0; i<=w;i++)
				F[w+1][i]=6;

		for(int i=0; i<=h;i++)
				F[i][h+1]=6;


		int N=0;
		while(N<n){
//cout <<N;
			cin >>c>>d>>x>>y;
//cout<<c<<d<<x<<y<<endl;
			if(d){
				for(int i=x; i<x+2; i++)
					for(int j=y; j<y+4; j++){
						F[i][j]=c;
//cout <<F[i][j];
				}
//cout <<endl;
			}else{
				for(int i=x; i<x+4; i++)
					for(int j=y; j<y+2; j++){
						F[i][j]=c;
//cout <<F[i][j];
					}
//cout <<endl;
			}
			N++;
		}

//for(int i=0; i<=101; i++){
	//for(int j=0; j<=101; j++){
		//cout <<F[j][i];
		//}
	//cout << endl;
//}
		
		Maze(xs,ys,F[xs][ys]);

		if(ok==0)
			cout <<"NG"<<endl;

	}

}