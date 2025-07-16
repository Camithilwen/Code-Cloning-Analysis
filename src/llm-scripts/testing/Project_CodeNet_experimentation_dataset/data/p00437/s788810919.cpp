#include<iostream>

int power[101];
int motor[101];
int cable[101];
int a, b, c, N;
int la[1024], lb[1024], lc[1024], lr[1024];

void print(){
	int i;
	for( i = 1; i <= a; i++ ){
		std::cout << power[i] << std::endl;
	}
	for( i = 1; i <= b; i++ ){
		std::cout << motor[i] << std::endl;
	}
	for( i = 1; i <= c; i++ ){
		std::cout << cable[i] << std::endl;
	}
	return;
}

int input(){
	int i;
	std::cin >> a >> b >> c;
	std::cin >> N;
	for( i = 1; i <= a; i++ ){
		power[i] = 2;
	}
	for( i = 1; i <= b; i++ ){
		motor[i] = 2;
	}
	for( i = 1; i <= c; i++ ){
		cable[i] = 2;
	}
	for( i = 0; i < N; i++ ){
		std::cin >> la[i] >> lb[i] >> lc[i] >> lr[i];
	}
	return (a+b+c);
}

void check(){
	int x, y, z, i;
	for( i = 0; i < N; i++ ){
		if( lr[i] == 0 ){ continue; }
		x = la[i];
		y = lb[i] - a;
		z = lc[i] - a - b;
		power[x] = 1;
		motor[y] = 1;
		cable[z] = 1;
	}
	for( i = 0; i < N; i++ ){
		if( lr[i] == 1 ){ continue; }
		x = la[i];
		y = lb[i] - a;
		z = lc[i] - a - b;
		if( motor[y] == 1 && cable[z] == 1 ){
			power[x] = 0;
		}else if( power[x] == 1 && cable[z] == 1 ){
			motor[y] = 0;
		}else if( power[x] == 1 && motor[y] == 1 ){
			cable[z] = 0;
		}
	}
	return;
}

int main(){
	while( input() != 0 ){
		check();
		print();
	}
	return 0;
}