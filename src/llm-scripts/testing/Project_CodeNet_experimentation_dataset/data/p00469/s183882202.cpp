#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int n, k;
string str[10];

int main(){
	while(scanf("%d", &n),n){
		set<string> s;
		scanf("%d", &k);
		rep(i,n) cin >> str[i];
		if(k == 2){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(i == j) continue;
					s.insert(str[i]+str[j]);
				}
			}
		} else if(k == 3){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(j == i) continue;
					for(int u = 0; u < n; u++){
						if(u == i || u == j) continue;
						s.insert(str[i]+str[j]+str[u]);
					}
				}
			}
		} else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(i == j) continue;
					for(int u = 0; u < n; u++){
						if(u == i || u == j) continue;
						for(int v = 0; v < n; v++){
							if(v == i || v == j || v == u) continue;
							s.insert(str[i]+str[j]+str[u]+str[v]);
						}
					}
				}
			}
		}
		cout << s.size() << endl;
	}
}