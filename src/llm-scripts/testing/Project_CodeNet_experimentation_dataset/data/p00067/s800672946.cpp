#include<iostream>
#include<string>
#define COL 12
#define ROW 12
using namespace std;
	int field[COL][ROW];

void mapping(int y, int x){
	//cout<<"mapping("<<y<<", "<<x<<")\n";
	if(field[y][x]==1){
		field[y][x]=0;
		if(y+1<COL) mapping(y+1,x);
		if(x+1<COL) mapping(y,x+1);
		if(y-1>=0)  mapping(y-1,x);
		if(x-1>=0)  mapping(y,x-1);
	}
	return;
}

int main(){
	string str;
	int i, j,cnt;
	bool loop = true;
	while(true){
		for(i=0;i<COL;i++){
			cin>>str;
			if(cin.eof()){
				loop = false;
				break;
			}
			for(j=0;j<ROW;j++){
				field[i][j] = str[j] - '0';
			}
		}
		if(loop==false) break;
		cnt=0;
		for(i=0;i<COL;i++){
			for(j=0;j<ROW;j++){
				if(field[i][j]==1){
					mapping(i,j);
					cnt++;
				};
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}