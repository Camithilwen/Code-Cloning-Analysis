#define	_USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
using namespace std;
char shima[13][13];
void tansaku(int x,int y){
	if(x<0||x>11||y<0||y>11||shima[y][x]=='0')
		return ;
	if(shima[y][x]=='1'){
		shima[y][x]='0';
	}
	tansaku(x+1,y);
	tansaku(x-1,y);
	tansaku(x,y+1);
	tansaku(x,y-1);
	
}
int main(){
	
	while(cin>>shima[0][0]){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			if(i==0&&j==0)
			continue;
			else
			cin>>shima[i][j];
		}
	}
		int a=0;
		for(int i=0;i<12;i++){
			for(int j=0;j<12;j++){
				if(shima[i][j]=='1'){
					tansaku(j,i);
					a++;
				}
			}
		}
		cout<<a<<endl;
	}
}

	