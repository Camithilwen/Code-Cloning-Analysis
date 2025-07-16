#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define N 8
using namespace std;

stack<char> s[N][N];
char map[N][N];
int kazu;

void post(int a,int b){
	for(int i=0;i<N;i++){
		s[i][b].push(1);
		if(i!=b) s[a][i].push(1);
	}
	for(int i=1;i+a<N&&i+b<N;i++){
		s[a+i][b+i].push(1);
	}
	for(int i=1;a-i>=0&&b-i>=0;i++){
		s[a-i][b-i].push(1);
	}
	for(int i=1;a+i<N&&b-i>=0;i++){
		s[a+i][b-i].push(1);
	}
	for(int i=1;a-i>=0&&b+i<N;i++){
		s[a-i][b+i].push(1);
	}
}

void receive(int a,int b){
	for(int i=0;i<N;i++){
		s[i][b].pop();
		if(i!=b)s[a][i].pop();
	}
	for(int i=1;i+a<N&&i+b<N;i++){
		s[a+i][b+i].pop();
	}
	for(int i=1;a-i>=0&&b-i>=0;i++){
		s[a-i][b-i].pop();
	}
	for(int i=1;a+i<N&&b-i>=0;i++){
		s[a+i][b-i].pop();
	}
	for(int i=1;a-i>=0&&b+i<N;i++){
		s[a-i][b+i].pop();
	}

}

void view(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

void rop(int a,int b){
	map[a][b]='Q';
	post(a,b);
	kazu++;
	if(kazu>=8){
		view();
		exit(0);
	}
	for(int i=a+1;i<N;i++){
		for(int j=0;j<N;j++){
			if(s[i][j].empty()) rop(i,j);
		}
	}
		receive(a,b);
		map[a][b]='.';
		kazu--;
}

int main(void){
	int n;
	int a,b;

	kazu=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			map[i][j]='.';
		}
	}

	cin>>n;
	while(n--){
		cin>>a>>b;
		map[a][b]='Q';
		post(a,b);
		kazu++;
	}

	if(kazu==8){
		view();
		exit(0);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(s[i][j].empty()){
				rop(i,j);
			}
		}
	}
	return 0;
}