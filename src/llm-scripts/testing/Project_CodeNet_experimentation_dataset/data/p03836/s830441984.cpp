#include<iostream>
using namespace std;
int main(){
	int sx, sy, tx,ty;
	cin >> sx >> sy >> tx >> ty;
	for(int i = 0; i<(ty- sy); i++){
		cout << 'U';
	} 
	for(int i = 0; i<(tx- sx); i++){
		cout << 'R';
	} 
	for(int i = 0; i<(ty- sy); i++){
		cout << 'D';
	} 
	for(int i = 0; i<(tx- sx); i++){
		cout << 'L';
	}
	 
	int csx = sx, csy =sy, ctx = tx,cty = ty;
	csx -= 1;
	cty += 1;
	cout << 'L'; 
	for(int i = 0; i<(cty- csy); i++){
		cout << 'U';
	}
	for(int i = 0; i<(ctx- csx); i++){
		cout << 'R';
	} 
	 cout << 'D';
	 
	ctx = tx +1;
	csy = sy -1; 
	csx = sx, cty = ty; 
	cout << 'R';  
	for(int i = 0; i<(cty- csy); i++){
		cout << 'D';
	} 
	for(int i = 0; i<(ctx- csx); i++){
		cout << 'L';
	} 
	cout << 'U';
	
	return 0;
}