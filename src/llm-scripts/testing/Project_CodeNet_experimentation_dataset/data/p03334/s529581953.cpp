#include<bits/stdc++.h>
using namespace std;

bool vis[603][603]; int N , D1 , D2;
void color(int dist){
	int now = 0; while(!(dist & 3)){dist >>= 2; ++now;}
	if(dist % 4 == 3) return;
	for(int i = 0 ; i < 2 * N ; ++i)
		for(int j = 0 ; j < 2 * N ; ++j)
			vis[i][j] |= ((dist & 2) && (i >> now & 1)) || ((dist & 1) && (((i >> now) + (j >> now)) & 1));
}

int main(){
	cin >> N >> D1 >> D2; color(D1); color(D2); int num = 0;
	for(int i = 0 ; i < 2 * N ; ++i) for(int j = 0 ; j < 2 * N ; ++j) if(!vis[i][j] && ++num <= N * N) printf("%d %d\n" , i , j);
	return 0;
}