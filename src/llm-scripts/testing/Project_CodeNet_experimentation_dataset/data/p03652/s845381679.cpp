#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, m;
int pref[303][303];

int ptr[303];
int freq[303];

queue<int> Q;

bool die[303];

void incre(int j, int c){
//	printf(" ++%d\n", j);
	freq[j]++;
	if(freq[j] == c + 1){
//		printf("c = %d, die %d\n", c, j);
		die[j] = true;
		Q.push(j);
	}
}

bool possible(int c){
	// can choose with <= c ppl per event?
	memset(freq, 0, sizeof(freq));
	
	while(!Q.empty()){
		Q.pop();
	}
	
	for(int j = 1; j <= m; j++){
		die[j] = false;
	}
	
	for(int i = 1; i <= n; i++){
		ptr[i] = 1;
		incre(pref[i][1], c);
	}
	
	while(!Q.empty()){
		int del = Q.front();
		Q.pop();
		for(int i = 1; i <= n; i++){
			while(ptr[i] <= m && die[pref[i][ptr[i]]]){
				ptr[i]++;
				incre(pref[i][ptr[i]], c);
			}
		}
	}
	
	for(int j = 1; j <= m; j++){
		if(!die[j]){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &pref[i][j]);
		}
	}
	int l = 0, r = n;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(possible(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	printf("%d\n", r);
	return 0;
}